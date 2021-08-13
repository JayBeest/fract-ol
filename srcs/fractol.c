#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"
#include "../mlx/mlx.h"


//void	init_scene(t_scene *scene)
//{
//
//}

void	init_default_scene(t_scene *scene)
{
	scene->res.x = DEFAULT_RES_X;
	scene->res.y = DEFAULT_RES_Y;
	scene->current_fractal = MANDELBROT;
	scene->zoom = 1;
	scene->offset.x = -100;
	scene->offset.y = 0;
	scene->mouse.x = -1;
	scene->mouse.y = -1;
}

void 	init_mlx(t_mlx *mlx, const t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx_ptr, scene->res.x, scene->res.y, PROJECT);
}

void init_mlx_image(t_mlx *mlx, t_scene *scene, t_img_data *image)
{
	image->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->res.x, scene->res.y);
	image->img_address = mlx_get_data_addr(image->img_ptr, &image->bits_per_pixel, &image->line_lenght, &image->endian);

}

void    put_pixel(t_img_data *image, t_position position, unsigned int colour)
{
	char	*pixel_address;
	int		offset;

	offset = position.y * image->line_lenght + position.x * (image->bits_per_pixel / 8);
	pixel_address = image->img_address + offset;
	*(unsigned int *)pixel_address = colour;
}

unsigned int fetch_colour(int n)
{
	unsigned int		colour;
	static unsigned int test_colour;

	test_colour++;
	colour = 0xe21515 + 40 * n;
	if (n == 0)
		return (0x000000);
	if (n > 18)
		colour = 0x22ff2f + 5 * n;
	return (colour );
	return (test_colour);
}

int mandelbrot(t_complex_position complex_position)
{
	int			iterations;
	double 		temp;
	t_complex 	c;
	t_complex 	z;

	c = complex_position.c;
//	printf("c.real = %f\n", c.real);
//	printf("c.i = %f\n", c.i);
	z = complex_position.z;
	iterations = 0;
	while (iterations < 30)
	{
		temp = z.real;
		z.real = z.real * z.real - z.i * z.i + c.real;
		z.i = 2 * temp * z.i + c.i;
		iterations++;
		if (z.real * z.real + z.i * z.i > 4)
			return (iterations);
	}
	return (0);
}

int control_menu(t_mlx *mlx)
{
	t_position	pos;
	int 		color;

	color = 0x22ff2f;
	pos.x = mlx->scene.res.x - 200;
	pos.y = mlx->scene.res.y - 300;
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, "MENU");
	return (1);
}

int debug_menu(t_mlx *mlx)
{
	int 		color;
	t_position	pos;
	t_resolution	min_res;
	t_resolution	max_res;
	char	real[50];
	char 	i[50];

	snprintf(real, 40, "real: %f\n", mlx->scene.complex_position.c.real);
	snprintf(i, 40, "i   : %f\n", mlx->scene.complex_position.c.i);
	color = 0xffffff;
	min_res.x = 0;
	min_res.y = 0;
	max_res.x = mlx->scene.res.x;
	max_res.y = mlx->scene.res.y;
	pos.x = mlx->scene.res.x - 200;
	pos.y = 20;
	if (mlx->scene.mouse.x >= min_res.x && mlx->scene.mouse.x <= max_res.x)
		if (mlx->scene.mouse.y >= min_res.y && mlx->scene.mouse.y <= max_res.y)
		{
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, ft_itoa(mlx->scene.mouse.x));
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 10, color, ft_itoa(mlx->scene.mouse.y));
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 30, color, real);
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 40, color, i);

		}
	return (1);
}

void	calculate_complex_position(t_scene *scene, t_position pos)
{
	double 				zoom;
	t_grid_position 	grid_position;
	t_complex_position	*complex_pos;

	complex_pos = &scene->complex_position;
	grid_position.x = (double)pos.x - (double)scene->res.x / 2 + scene->offset.x;
	grid_position.y = (double)pos.y - (double)scene->res.y / 2 + scene->offset.y;
	zoom = ((double)scene->res.x / scene->zoom);
	complex_pos->c.real = grid_position.x / zoom * DEFAULT_ZOOM;
	complex_pos->c.i = - grid_position.y / zoom * DEFAULT_ZOOM;
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

int	kill(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
	printf("Yo\n");
	exit (1);
}

int mouse_button(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
		mlx->scene.zoom *= ZOOM_FACTOR;
	else if (button == 5)
		mlx->scene.zoom /= ZOOM_FACTOR;
	x = 0;
	y = 0;
	draw_fractal_to_image(mlx);
	return (1);
}

int mouse_move(int x, int y, t_mlx *mlx)
{
	t_position	position;

	position.x = x;
	position.y = y;

	calculate_complex_position(&mlx->scene, position);
	mlx->scene.mouse.x = x;
	mlx->scene.mouse.y = y;
//	printf("x: %d\n", x);s
//	printf("y: %d\n", y);
//	redraw_image(mlx);
	return (1);
}

int	keypress(t_key key_code, t_mlx *mlx)
{
		if (key_code == A)
			mlx->scene.offset.x -= STEP;
		else if (key_code == D)
			mlx->scene.offset.x += STEP;
		else if (key_code == S)
			mlx->scene.offset.y += STEP;
		else if (key_code == W)
			mlx->scene.offset.y -= STEP;
	if (key_code == ESC)
		kill(mlx);
	draw_fractal_to_image(mlx);
	return (1);
}


int	main(int argc, char **argv)
{
	t_mlx			mlx;

	if (argc == 1)
		init_default_scene(&mlx.scene);
//	else
		//init_scene();
	init_mlx(&mlx, &mlx.scene);
	init_mlx_image(&mlx, &mlx.scene, &mlx.image);
	draw_fractal_to_image(&mlx);
	printf("\n %s\n", argv[0]);
	mlx_hook(mlx.mlx_window, KeyRelease, KeyReleaseMask, keypress, &mlx);
	mlx_hook(mlx.mlx_window, DestroyNotify, StructureNotifyMask, kill, &mlx);
	mlx_hook(mlx.mlx_window, ButtonPress, ButtonPressMask, mouse_button, &mlx);
	mlx_hook(mlx.mlx_window, MotionNotify, PointerMotionMask, mouse_move, &mlx);

	mlx_loop_hook(mlx.mlx_ptr,redraw_image, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

