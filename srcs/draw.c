#include "mlx.h"
#include "defines.h"
#include "datatypes.h"
#include "utils.h"
#include "fractols.h"
#include "colour.h"
#include "menu.h"

void static	put_pixel(t_mlx *mlx, t_position position, unsigned int colour)
{
	char	*pixel_address;
	int		offset;

	if (mlx->scene.current_fractal == SHIP)
		position.y = RESOLUTION_Y - position.y;
	offset = position.y * mlx->image.line_length + position.x * \
		(mlx->image.bits_per_pixel / 8);
	pixel_address = mlx->image.img_address + offset;
	*(unsigned int *)pixel_address = colour;
}

void static	redraw_window(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, \
		mlx->image.img_ptr, 0, 0);
	mlx->scene.complex_position = pos_to_complex_pos(mlx->scene.plane, \
		mlx->scene.mouse);
	if (mlx->scene.control_menu)
	{
		controls_menu(*mlx);
		info_menu(*mlx);
	}
}

unsigned int static	calculate_fractal(t_scene *scene, t_position pos)
{
	int						n;
	const t_fractal_f_ptr	fun_ptr[3] = {
			[MANDELBROT] = mandelbrot,
			[JULIA] = julia,
			[SHIP] = burning_ship
	};

	scene->complex_position = pos_to_complex_pos(scene->plane, pos);
	n = fun_ptr[scene->current_fractal](*scene);
	return (fetch_colour(n, scene->colours, scene->iteration_amount));
}

int	draw_fractal_to_image(t_mlx *mlx)
{
	t_position						position;
	unsigned int					colour;

	mlx->scene.plane = calculate_complex_plane(mlx->scene);
	position.y = 0;
	if (mlx->scene.psycho)
		mlx->scene.colours.colour_mixer_3++;
	while (position.y < mlx->scene.res.y)
	{
		position.x = 0;
		while (position.x < mlx->scene.res.x)
		{
			colour = calculate_fractal(&mlx->scene, position);
			put_pixel(mlx, position, colour);
			position.x++;
		}
		position.y++;
	}
	redraw_window(mlx);
	return (1);
}
