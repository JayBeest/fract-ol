#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"
#include "./mlx/mlx.h"

//void	init_scene(t_scene *scene)
//{
//
//}

void	init_default_scene(t_scene *scene)
{
	scene->res.x = DEFAULT_RES_X;
	scene->res.y = DEFAULT_RES_Y;
	scene->current_fractal = MANDELBROT;
	scene->zoom = DEFAULT_ZOOM;
	scene->offset.x = 0;
	scene->offset.y = 0;
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
	if (n == 0)
		return (0x000000);
	colour = 40 * n + 0xe21515;
	return (colour);
	return (test_colour);
}

int mandelbrot(t_complex_position complex_position)
{
	int			iterations;
	double 		temp;
	t_complex 	c;
	t_complex 	z;

	c = complex_position.c;
	z = complex_position.z;
	iterations = 0;
	while (iterations < 50)
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

unsigned int calculate_fractal(t_scene *scene, t_position pos)
{
	int 				n;
	t_grid_position 	grid_position;
	t_complex_position	complex_pos;
	double 				zoom;

	grid_position.x = (double)pos.x - (double)scene->res.x / 2 + scene->offset.x;
	grid_position.y = (double)pos.y - (double)scene->res.y / 2 + scene->offset.y;
	zoom = ((double)scene->res.x / scene->zoom);
	complex_pos.c.real = grid_position.x / zoom;
	complex_pos.c.i =  grid_position.y / zoom;
	complex_pos.z.real = 0;
	complex_pos.z.i = 0;
	n = mandelbrot(complex_pos);
	return (fetch_colour(n));
}

void draw_image(t_mlx *mlx, t_scene *scene, t_img_data *image)
{
	t_position		position;
	unsigned int	colour;

	position.y = 0;
	while (position.y < scene->res.y)
	{
		position.x = 0;
		while (position.x < scene->res.x)
		{
			colour = calculate_fractal(scene, position);
			put_pixel(image, position, colour);
			position.x++;
		}
		position.y++;
	}
	position.x = 50;
	position.y = 50;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, image->img_ptr, 0, 0);
}

int	kill(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
	printf("Yo\n");
	exit (1);
}

int	keypress(t_key key_code, t_mlx *mlx)
{
		if (key_code == A)
			printf("A\n");
		else if (key_code == D)
			printf("D\n");
		else if (key_code == S)
			printf("S\n");
		else if (key_code == W)
			printf("W\n");
	if (key_code == ESC)
		kill(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx			mlx;
	t_scene			scene;
	t_img_data		image;

	if (argc == 1)
		init_default_scene(&scene);
//	else
		//init_scene();
	init_mlx(&mlx, &scene);
	init_mlx_image(&mlx, &scene, &image);
	draw_image(&mlx, &scene, &image);
	printf("\n %s\n", argv[0]);
	mlx_hook(mlx.mlx_window, KeyRelease, KeyReleaseMask, keypress, &mlx);
//	mlx_key_hook(mlx.mlx_window, keypress, &mlx);
	mlx_hook(mlx.mlx_window, DestroyNotify, StructureNotifyMask, kill, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
