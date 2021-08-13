#include <stdlib.h>
#include "../mlx/mlx.h"
#include "datatypes.h"
#include "draw.h"

#include "main.h"

int	kill(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
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