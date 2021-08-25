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

	mouse.x = x;
	mouse.y = y;
	printf("button nr.: %d\n", button);
	if (mouse.x < 0 || mouse.y < 0 || mouse.x > mlx->scene.res.x || mouse.y > mlx->scene.res.y)
		return (1);
	if (button == 1 && mlx->scene.current_fractal == MANDELBROT)
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
	if (key_code == LEFT)
		mlx->scene.offset.x -= STEP;
	else if (key_code == RIGHT)
		mlx->scene.offset.x += STEP;
	else if (key_code == DOWN)
		mlx->scene.offset.y += STEP;
	else if (key_code == UP)
		mlx->scene.offset.y -= STEP;
	else if (key_code == M)
		switch_bool(&mlx->scene.zoom_to_mouse);
	else if (key_code == N)
		switch_bool(&mlx->scene.julia_animation);
	else if (key_code == P)
		switch_bool(&mlx->scene.psycho);
	else if (key_code == J)
		mlx->scene.colours.colour_mixer_1 += 5;
	else if (key_code == K)
		mlx->scene.colours.colour_mixer_2 += 5;
	else if (key_code == L)
		mlx->scene.colours.colour_mixer_2++;
	else if (key_code == Z)
		mlx->scene.julia = position_to_complex_position(mlx->scene.plane, mlx->scene.mouse);
	else if (key_code == B_SPACE)
		return_to_origin(&mlx->scene);
	else if (key_code == PLUS && mlx->scene.iteration_amount < 1000)
		mlx->scene.iteration_amount += 10;
	else if (key_code == MIN && mlx->scene.iteration_amount > 10)
		mlx->scene.iteration_amount -= 10;
	else if (key_code == A && mlx->scene.current_fractal < JULIA)
		mlx->scene.current_fractal++;
	else if (key_code == D && mlx->scene.current_fractal > MANDELBROT)
		mlx->scene.current_fractal--;
	else if (key_code == ESC)
		kill(mlx);
//	draw_fractal_to_image(mlx);
	return (1);
}