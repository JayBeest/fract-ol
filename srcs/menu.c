#include <stdio.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "datatypes.h"

int control_menu(t_mlx *mlx)
{
	t_position	pos;
	int 		color;

	color = 0x22ff2f;
	pos.x = mlx->scene.res.x - 200;
	pos.y = mlx->scene.res.y - 300;
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, "MENU");
	return (1);
}

int debug_menu(t_mlx *mlx)
{
	int 		color;
	t_position	pos;
	t_resolution	min_res;
	t_resolution	max_res;
	char	real[50];
	char 	i[50];
	char 	zoom[50];

	snprintf(real, 40, "real: %f\n", mlx->scene.complex_position.c.real);
	snprintf(i, 40, "i   : %f\n", mlx->scene.complex_position.c.i);
	snprintf(zoom, 40, "zoom: %f\n", mlx->scene.zoom);
	color = 0xffffff;
	min_res.x = 0;
	min_res.y = 0;
	max_res.x = mlx->scene.res.x;
	max_res.y = mlx->scene.res.y;
	pos.x = mlx->scene.res.x - 200;
	pos.y = 20;
	if (mlx->scene.mouse.x >= min_res.x && mlx->scene.mouse.x <= max_res.x)
		if (mlx->scene.mouse.y >= min_res.y && mlx->scene.mouse.y <= max_res.y)
		{
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, ft_itoa(mlx->scene.mouse.x));
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 10, color, ft_itoa(mlx->scene.mouse.y));
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 30, color, real);
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 40, color, i);
			mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 60, color, zoom);
		}
	return (1);
}