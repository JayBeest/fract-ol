#include "datatypes.h"
#include "../mlx/mlx.h"
#include "main.h"
#include "utils.h"
#include "fractols.h"
#include "menu.h"

#include "stdio.h"

void    put_pixel(t_img_data *image, t_position position, unsigned int colour)
{
	char	*pixel_address;
	int		offset;

	offset = position.y * image->line_length + position.x * (image->bits_per_pixel / 8);
	pixel_address = image->img_address + offset;
	*(unsigned int *)pixel_address = colour;
}

void	calculate_complex_position(t_scene *scene, t_position pos)
{
	t_complex_position		*complex_pos;
	t_complex_plane_info	plane;

	plane = scene->plane;
	complex_pos = &scene->complex_position;
	complex_pos->c.re = pos.x * plane.step + scene->plane.min.re;
	complex_pos->c.im = pos.y * plane.step + scene->plane.min.im;
	complex_pos->z.re = 0;
	complex_pos->z.im = 0;
}

unsigned int calculate_fractal(t_scene *scene, t_position pos)
{
	t_complex_position	*complex_position;
	int 				n;

	complex_position = &scene->complex_position;
	calculate_complex_position(scene, pos);
	n = mandelbrot(*complex_position, scene->iteration_amount);
//	n = julia(*complex_position, scene->julia, scene->iteration_amount);
	return (fetch_colour(n, scene->colours));
}

void calculate_complex_plane(t_scene *scene)
{
	t_complex	*min_pos;
	t_complex	*max_pos;
//	t_complex	*offset;

	min_pos = &scene->plane.min;
	max_pos = &scene->plane.max;
//	offset = &scene->plane.offset;
	min_pos->re = (scene->offset.x - RESOLUTION_X / 2) / scene->zoom;
	max_pos->re = min_pos->re + RESOLUTION_X / scene->zoom;
	scene->plane.step = (max_pos->re - min_pos->re) / RESOLUTION_X;
	min_pos->im = (scene->offset.y - RESOLUTION_Y / 2) / scene->zoom;
	max_pos->im = min_pos->im + RESOLUTION_Y / scene->zoom;
}

int draw_fractal_to_image(t_mlx *mlx)
{
	t_position		position;
	unsigned int	colour;

	calculate_complex_plane(&mlx->scene);
	position.y = 0;
	while (position.y < mlx->scene.res.y)
	{
		position.x = 0;
		while (position.x < mlx->scene.res.x)
		{
			colour = calculate_fractal(&mlx->scene, position);
			put_pixel(&mlx->image, position, colour);
			position.x++;
		}
		position.y++;
	}
	//	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->image.img_ptr, 0, 0);
	//	control_menu(mlx);
	//	debug_menu(mlx);
	return (1);
}

int	redraw_image(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->image.img_ptr, 0, 0);
	control_menu(mlx);
	debug_menu(mlx);
	return (1);
}

