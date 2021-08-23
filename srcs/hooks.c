#include <stdlib.h>
#include "../mlx/mlx.h"
#include "datatypes.h"
#include "draw.h"
#include "utils.h"

#include "main.h"

int	kill(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
	exit (1);
}

int mouse_button(int button, int x, int y, t_mlx *mlx)
{
	t_position	mouse;
	t_position	*offset;

	mouse.x = x;
	mouse.y = y;
	offset = &mlx->scene.offset;
	if (button == 1)
		center_on_mouse(mouse, &mlx->scene);
	if (button == 2)
		return_to_origin(&mlx->scene);
	else if (button == 4)
	{
		mlx->scene.zoom *= ZOOM_FACTOR;
//		offset-> = offset->x + (mlx->scene.res.x >> 1)ZOOM_FACTOR;
	}
	else if (button == 5)
	{
		mlx->scene.zoom /= ZOOM_FACTOR;
//		mlx->scene.plane.offset.y /= ZOOM_FACTOR;
	}
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
	mlx->scene.mouse.x = x;
	mlx->scene.mouse.y = y;
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