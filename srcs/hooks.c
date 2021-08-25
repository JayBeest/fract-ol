#include <stdlib.h>
#include "../mlx/mlx.h"
#include "datatypes.h"
#include "draw.h"
#include "utils.h"
#include "actions.h"

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

	mouse.x = x;
	mouse.y = y;
	printf("button nr.: %d\n", button);
	if (mouse.x < 0 || mouse.y < 0 || mouse.x > mlx->scene.res.x || mouse.y > mlx->scene.res.y)
		return (1);
	if (button == 1)
		center_on_mouse(mouse, &mlx->scene);
	else if (button == 2)
		mlx->scene.mouse = mouse;
	else if (button == 4)
 		zoom_in(&mlx->scene, mouse);
	else if (button == 5)
		zoom_out(&mlx->scene, mouse);
	draw_fractal_to_image(mlx);
	return (1);
}

int mouse_move(int x, int y, t_mlx *mlx)
{
	t_position		mouse_pos;

	mouse_pos.x = x;
	mouse_pos.y = y;
	if (mouse_pos.x >= 0 && mouse_pos.y >= 0 && mouse_pos.x <= mlx->scene.res.x && mouse_pos.y <= mlx->scene.res.y)
	{
		mlx->scene.complex_position = position_to_complex_position(mlx->scene.plane, mouse_pos);
		mlx->scene.mouse = mouse_pos;
		if (mlx->scene.julia_animation)
		{
			mlx->scene.julia.c = mlx->scene.complex_position.c;
		}
	}
	return (1);
}

int	keypress(t_key key_code, t_mlx *mlx)
{
	printf("key_code nr.: %d\n", key_code);
	if (key_code == RIGHT || key_code == LEFT || key_code == UP || key_code == DOWN || key_code == A || key_code == D)
		key_action_controls(&mlx->scene, key_code);
	else if (key_code == PLUS || key_code == MIN || key_code == B_SPACE || key_code == M || key_code == N || key_code == Z)
		key_action_settings(&mlx->scene, key_code);
	else if (key_code == J || key_code == K || key_code == L || key_code == W || key_code == S || key_code == P)
		key_action_colours(&mlx->scene, key_code);
	else if (key_code == ESC)
		kill(mlx);
	return (1);
}