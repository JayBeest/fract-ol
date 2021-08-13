#include "datatypes.h"
#include "../mlx/mlx.h"
#include "utils.h"
#include "fractols.h"
#include "menu.h"

#include "main.h"
#include "stdio.h"

void    put_pixel(t_img_data *image, t_position position, unsigned int colour)
{
	char	*pixel_address;
	int		offset;

	offset = position.y * image->line_lenght + position.x * (image->bits_per_pixel / 8);
	pixel_address = image->img_address + offset;
	*(unsigned int *)pixel_address = colour;
}

void	calculate_complex_position(t_scene *scene, t_position pos)
{
	double 				zoom;
	t_grid_position 	grid_position;
	t_complex_position	*complex_pos;

	complex_pos = &scene->complex_position;
	grid_position.x = (double)pos.x - (double)scene->res.x / 2 + scene->offset.x;
	grid_position.y = (double)pos.y - (double)scene->res.y / 2 + scene->offset.y;
//	printf("gridpos.x: %f\n", grid_position.x);
//	printf("gridpos.y: %f\n", grid_position.y);
	zoom = (((double)scene->res.x / 2) / scene->zoom );
	complex_pos->c.real = grid_position.x / zoom;
	complex_pos->c.i = - grid_position.y / zoom;
	complex_pos->z.real = 0;
	complex_pos->z.i = 0;
}

unsigned int calculate_fractal(t_scene *scene, t_position pos)
{
	t_complex_position	*complex_position;

	int 				n;

	complex_position = &scene->complex_position;
	calculate_complex_position(scene, pos);
	n = mandelbrot(*complex_position);
	return (fetch_colour(n));
}

int draw_fractal_to_image(t_mlx *mlx)
{
	t_position		position;
	unsigned int	colour;

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

