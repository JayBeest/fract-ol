#include <stdio.h>
#include <math.h>
#include "../mlx/mlx.h"
#include "main.h"
#include "datatypes.h"
#include "draw.h"
#include "hooks.h"
#include "parser.h"


//void	init_scene(t_scene *scene)
//{
//
//}

void	init_scene(t_scene *scene)
{

}

void	init_default_scene(t_scene *scene)
{
	scene->res.x = RESOLUTION_X;
	scene->res.y = RESOLUTION_Y;
	scene->current_fractal = MANDELBROT;
	scene->iteration_amount = DEFAULT_ITERATION;
//	scene->zoom_to_mouse = FALSE;
//	scene->colours.colour_mixer_1 = 40;
//	scene->colours.colour_mixer_2 = 5;
//	scene->colours.colour_mixer_3 = 1;
	scene->colours.colour_mixer_1 = 1;
	scene->colours.colour_mixer_2 = 1;
	scene->colours.colour_mixer_3 = 1;
	scene->default_zoom = scene->res.x / 4;
	scene->zoom = scene->default_zoom;
//	scene->offset.x = 0;
//	scene->offset.y = 0;
	scene->mouse.x = -1;
	scene->mouse.y = -1;
//	scene->julia.re = 0;
//	scene->julia.im = 0;
//	scene->julia_animation = FALSE;
//	scene->psycho = FALSE;
}

void 	init_mlx(t_mlx *mlx, const t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx_ptr, scene->res.x, scene->res.y, PROJECT);
}

void init_mlx_image(t_mlx *mlx, t_scene *scene, t_img_data *image)
{
	image->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->res.x, scene->res.y);
	image->img_address = mlx_get_data_addr(image->img_ptr, &image->bits_per_pixel, &image->line_length, &image->endian);

}

int	main(int argc, char **argv)
{
	static t_mlx	mlx;
	t_bool_err		parse_success;

	printf("sizeof(double) = %lu\nsizeof(long double) = %lu\n", sizeof(double), sizeof(long double));

	init_default_scene(&mlx.scene);
	parse_success = parse_arguments(argc, (const char**)argv, &mlx.scene);
	if (parse_success.bool)
		printf("\nParse SUCCESS!!\n");
	else
	{
		printf("error no: %d\n", parse_success.error_nr);
		return (1);
	}
	init_mlx(&mlx, &mlx.scene);
	init_mlx_image(&mlx, &mlx.scene, &mlx.image);
	draw_fractal_to_image(&mlx);
	printf("\n %s\n", argv[0]);
	mlx_hook(mlx.mlx_window, KeyRelease, KeyReleaseMask, keypress, &mlx);
	mlx_hook(mlx.mlx_window, DestroyNotify, StructureNotifyMask, kill, &mlx);
	mlx_hook(mlx.mlx_window, ButtonPress, ButtonPressMask, mouse_button, &mlx);
	mlx_hook(mlx.mlx_window, MotionNotify, PointerMotionMask, mouse_move, &mlx);

	mlx_loop_hook(mlx.mlx_ptr,draw_fractal_to_image, &mlx);
//	mlx_loop_hook(mlx.mlx_ptr,redraw_image, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

