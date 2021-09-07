#include "mlx.h"
#include "libft.h"
#include "datatypes.h"

void	controls_menu(t_mlx mlx)
{
	int	x_pos;

	x_pos = mlx.scene.res.x - 325;
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 15, 0xffffff, \
	"Control menu	(toggle)       -   [F1]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 35, 0xffffff, \
	"Pan screen                 -   [Arrow Keys]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 45, 0xffffff, \
	"Zoom                       -   [Mouse Scroll]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 55, 0xffffff, \
	"Center on mouse            -   [Left Mouse]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 65, 0xffffff, \
	"Zoom to mouse (toggle)     -   [M]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 75, 0xffffff, \
	"Mouse to C (toggle/single) -   [N]/[Z]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 85, 0xffffff, \
	"Reset zoom/pan             -   [BackSpace]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 95, 0xffffff, \
	"Iterations                 -   [+]/[-]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 105, 0xffffff, \
	"Colour mixers              -   [J]/[K]/[L]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 115, 0xffffff, \
	"Psycho mode (toggle)       -   [P]");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, x_pos, 125, 0xffffff, \
	"Switch fractal type        -   [A]/[D]");
}

void	info_menu(t_mlx mlx)
{
	static const char	*fractal_type[3] = {"Mandelbrot", \
											"Julia", \
											"BurningShip"};
	t_position			pos;
	const char			*print;

	print = fractal_type[mlx.scene.current_fractal];
	pos.y = mlx.scene.res.y - 15;
	pos.x = mlx.scene.res.x - 30;
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, 15, pos.y, 0xffffff, \
		(char *)print);
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_window, pos.x, pos.y, 0xffffff, \
		ft_itoa(mlx.scene.iteration_amount));
}
