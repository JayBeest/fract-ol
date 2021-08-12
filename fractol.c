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
	scene->offset.x = -100;
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

int draw_image(t_mlx *mlx)
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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->image.img_ptr, 0, 0);
	return (1);
}

int	kill(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
	printf("Yo\n");
	exit (1);
}

int mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
		mlx->scene.zoom = mlx->scene.zoom * ZOOM_STEP;
	else if (button == 5)
		mlx->scene.zoom = mlx->scene.zoom / ZOOM_STEP;
	x = 0;
	y = 0;
//	draw_image(mlx);
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
//	draw_image(mlx);
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
	draw_image(&mlx);
	printf("\n %s\n", argv[0]);
	mlx_hook(mlx.mlx_window, KeyRelease, KeyReleaseMask, keypress, &mlx);
	mlx_hook(mlx.mlx_window, DestroyNotify, StructureNotifyMask, kill, &mlx);
	mlx_hook(mlx.mlx_window, ButtonPress, ButtonPressMask, mouse, &mlx);

	mlx_loop_hook(mlx.mlx_ptr,draw_image, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

