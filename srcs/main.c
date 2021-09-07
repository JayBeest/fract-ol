#include <stdio.h>
#include "mlx.h"
#include "defines.h"
#include "datatypes.h"
#include "draw.h"
#include "hooks.h"
#include "parser.h"

void	init_default_scene(t_scene *scene)
{
	scene->res.x = RESOLUTION_X;
	scene->res.y = RESOLUTION_Y;
	scene->setting = DEFAULT;
	scene->iteration_amount = DEFAULT_ITERATIONS;
	scene->colours.colour_mixer_1 = 1;
	scene->colours.colour_mixer_2 = 1;
	scene->colours.colour_mixer_3 = 1;
	if (scene->res.x * MANDEL_X_RATIO > scene->res.y * MANDEL_Y_RATIO)
		scene->default_zoom = scene->res.y / 3;
	else
		scene->default_zoom = scene->res.x / 4;
	scene->zoom = scene->default_zoom;
	scene->mouse.x = -1;
	scene->mouse.y = -1;
	scene->controls_menu = TRUE;
	scene->info_menu = TRUE;
}

void	init_mlx(t_mlx *mlx, const t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx_ptr, scene->res.x, \
		scene->res.y, PROJECT);
}

void	init_mlx_image(t_mlx *mlx, t_scene *scene, t_img_data *image)
{
	image->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->res.x, scene->res.y);
	image->img_address = mlx_get_data_addr(image->img_ptr, \
		&image->bits_per_pixel, &image->line_length, &image->endian);
}

void	setup_julia(t_scene *scene)
{
	if (scene->setting == DEFAULT)
	{
		scene->julia.c.re = 0;
		scene->julia.c.im = 0;
	}
	else if (scene->setting == EX1)
	{
		scene->julia.c.re = -0.831660;
		scene->julia.c.im = -0.206859;
	}
	else if (scene->setting == EX2)
	{
		scene->julia.c.re = 0.025000;
		scene->julia.c.im = 0.660000;
	}
	else if (scene->setting == EX3)
	{
		scene->julia.c.re = 0.380000;
		scene->julia.c.im = -0.120000;
	}
}

int	main(int argc, char **argv)
{
	static t_mlx	mlx;
	t_bool_err		parse_success;

	init_default_scene(&mlx.scene);
	parse_success = parse_arguments(argc, (const char **)argv, &mlx.scene);
	if (parse_success.bool)
		printf("\nParse SUCCESS!!\n");
	else
		return (1);
	setup_julia(&mlx.scene);
	init_mlx(&mlx, &mlx.scene);
	init_mlx_image(&mlx, &mlx.scene, &mlx.image);
	draw_fractal_to_image(&mlx);
	hook_to_mlx(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
