#include <stdlib.h>
#include "../mlx/mlx.h"
#include "datatypes.h"
#include "draw.h"
#include "utils.h"

#include "main.h"
#include <stdio.h>

int	kill(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
	exit (1);
}

int mouse_button(int button, int x, int y, t_mlx *mlx)
{
	t_position		mouse;
	t_grid_position	*offset;

	mouse.x = x;
	mouse.y = y;
	offset = &mlx->scene.offset;
	printf("button nr.: %d\n", button);
	if (button == 1)
		center_on_mouse(mouse, &mlx->scene);
	else if (button == 2)
		return_to_origin(&mlx->scene);
	else if (button == 4)
 		zoom_in(&mlx->scene, mouse);
	else if (button == 5)
		zoom_out(&mlx->scene, mouse);
	draw_fractal_to_image(mlx);
	return (1);
}

int mouse_move(int x, int y, t_mlx *mlx)
{
	t_position	mouse_pos;

	mouse_pos.x = x;
	mouse_pos.y = y;

//	calculate_complex_plane(&mlx->scene);
	calculate_complex_position(&mlx->scene, mouse_pos);
	mlx->scene.julia = mlx->scene.complex_position.c;
	mlx->scene.mouse.x = x;
	mlx->scene.mouse.y = y;
//	draw_fractal_to_image(mlx);
	//	redraw_image(mlx);
	return (1);
}

int	keypress(t_key key_code, t_mlx *mlx)
{
	printf("key_code nr.: %d\n", key_code);
	if (key_code == A)
		mlx->scene.offset.x -= STEP;
	else if (key_code == D)
		mlx->scene.offset.x += STEP;
	else if (key_code == S)
		mlx->scene.offset.y += STEP;
	else if (key_code == W)
		mlx->scene.offset.y -= STEP;
	else if (key_code == M)
		mlx->scene.zoom_to_mouse = TRUE;
	else if (key_code == J)
		mlx->scene.colours.colour_mixer_1 += 5;
	else if (key_code == K)
		mlx->scene.colours.colour_mixer_2 += 5;
	else if (key_code == L)
		mlx->scene.colours.colour_mixer_2++;
	else if (key_code == PLUS && mlx->scene.iteration_amount < 1000)
		mlx->scene.iteration_amount += 10;
	else if (key_code == MIN && mlx->scene.iteration_amount > 10)
		mlx->scene.iteration_amount -= 10;

	else if (key_code == ESC)
		kill(mlx);
	draw_fractal_to_image(mlx);
	return (1);
}