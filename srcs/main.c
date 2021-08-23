#include <stdio.h>
#include <math.h>
#include "../mlx/mlx.h"
#include "main.h"
#include "datatypes.h"
#include "draw.h"
#include "hooks.h"


//void	init_scene(t_scene *scene)
//{
//
//}

void	init_default_scene(t_scene *scene)
{
	scene->res.x = RESOLUTION_X;
	scene->res.y = RESOLUTION_Y;
	scene->current_fractal = MANDELBROT;
	scene->iteration_amount = DEFAULT_ITERATION;
	scene->zoom_to_mouse = FALSE;
//	scene->zoom = (scene->res.y >> 1) / 1.2;
	scene->zoom = 200;
	scene->offset.x = -100;
	scene->offset.y = 0;
	scene->mouse.x = -1;
	scene->mouse.y = -1;
	scene->julia.re = 0.2345;
	scene->julia.im = 1.23;
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

