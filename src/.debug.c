#include <stdio.h>
#include "datatypes.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

int debug_menu(t_mlx *mlx)
{
	int 		color;
	t_position	pos;
	t_position	mouse_pos;
	t_resolution	max_res;
	char	real[50];
	char 	i[50];
	char	jul_c_real[50];
	char 	jul_c_i[50];
	char 	zoom[50];
	char 	x_min[50];
	char 	x_max[50];
	char 	y_min[50];
	char 	y_max[50];
	char 	offset_x[50];
	char	offset_y[50];

	mouse_pos = mlx->scene.mouse;
	snprintf(x_min, 40, "x_min: %.20Lf\n", mlx->scene.plane.min.re);
	snprintf(x_max, 40, "x_max: %.20Lf\n", mlx->scene.plane.max.re);
	snprintf(y_min, 40, "y_min: %.20Lf\n", mlx->scene.plane.min.im);
	snprintf(y_max, 40, "y_max: %.20Lf\n", mlx->scene.plane.max.im);
	snprintf(offset_x, 40, "offset_x: %.20Lf\n", mlx->scene.offset.x);
	snprintf(offset_y, 40, "offset_y: %.20Lf\n", mlx->scene.offset.y);
	snprintf(real, 40, "re: %Lf\n", mlx->scene.complex_position.c.re);
	snprintf(i, 40, "im   : %Lf\n", mlx->scene.complex_position.c.im);
	snprintf(jul_c_real, 40, "re: %Lf\n", mlx->scene.julia.c.re);
	snprintf(jul_c_i, 40, "im   : %Lf\n", mlx->scene.julia.c.im);
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
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 150, color, offset_x);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 160, color, offset_y);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 180, color, jul_c_real);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y + 190, color, jul_c_i);
	}
	return (1);
}


unsigned int	fetch_colour1(unsigned int n, t_colours colours, \
unsigned int max_iterations)
							  {
	unsigned int	test_colour;

	if (n == max_iterations)
		return (0x000000);
	test_colour = rgb_to_hex(colours.colour_mixer_1 * n, \
	colours.colour_mixer_2 * n, colours.colour_mixer_3 * n);
							 return (test_colour);
}

unsigned int	fetch_colour2(unsigned int n, t_colours colours, \
unsigned int max_iterations)
							  {
	unsigned int		colour;

	if (n == max_iterations)
		return (0x000000);
	colour = (0xe21515 + colours.colour_mixer_1 * n) / colours.colour_mixer_3;
	if (n > 18)
		colour = (0x22ff2f + colours.colour_mixer_2 * n) / \
		colours.colour_mixer_3;
				return (colour);
}
