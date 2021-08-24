#include <stdio.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "datatypes.h"
#include "main.h"

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
	t_position	mouse_pos;
	t_resolution	max_res;
	char	real[50];
	char 	i[50];
	char 	zoom[50];
	char 	x_min[50];
	char 	x_max[50];
	char 	y_min[50];
	char 	y_max[50];

	mouse_pos = mlx->scene.mouse;
	snprintf(x_min, 40, "x_min: %.20Lf\n", mlx->scene.plane.min.re);
	snprintf(x_max, 40, "x_max: %.20Lf\n", mlx->scene.plane.max.re);
	snprintf(y_min, 40, "y_min: %.20Lf\n", mlx->scene.plane.min.im);
	snprintf(y_max, 40, "y_max: %.20Lf\n", mlx->scene.plane.max.im);
	snprintf(real, 40, "re: %Lf\n", mlx->scene.complex_position.c.re);
	snprintf(i, 40, "im   : %Lf\n", mlx->scene.complex_position.c.im);
	snprintf(zoom, 40, "zoom: %LE\n", mlx->scene.zoom / mlx->scene.default_zoom);
	color = 0xffffff;
	max_res.x = mlx->scene.res.x;
	max_res.y = mlx->scene.res.y;
	pos.x = mlx->scene.res.x - 250;
	pos.y = 20;
	if (mouse_pos.x >= 0 && mouse_pos.y >= 0 && mouse_pos.x <= mlx->scene.res.x && mouse_pos.y <= mlx->scene.res.y)
	{
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, ft_itoa(mlx->scene.mouse.x));
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 10, color, ft_itoa(mlx->scene.mouse.y));
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 30, color, real);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 40, color, i);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 60, color, zoom);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 70, color, x_min);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 80, color, x_max);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 90, color, y_min);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 100, color, y_max);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 120, color, ft_itoa(mlx->scene.iteration_amount));
	}
	return (1);
}