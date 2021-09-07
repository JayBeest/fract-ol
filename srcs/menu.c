#include "../mlx/mlx.h"
#include "datatypes.h"

void	control_menu(t_mlx *mlx)
{
	int	x_pos;

	x_pos = mlx->scene.res.x - 350;
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 10, 0xffffff, \
	"Control menu	(toggle)       -   [F1]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 30, 0xffffff, \
	"Pan screen                 -   [Arrow Keys]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 40, 0xffffff, \
	"Zoom                       -   [Mouse Scroll]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 50, 0xffffff, \
	"Center on mouse            -   [Left Mouse]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 60, 0xffffff, \
	"Zoom to mouse (toggle)     -   [M]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 70, 0xffffff, \
	"Mouse to C (toggle/single) -   [N]/[Z]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 80, 0xffffff, \
	"Reset zoom/pan             -   [BackSpace]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 90, 0xffffff, \
	"Iterations                 -   [+]/[-]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 100, 0xffffff, \
	"Colour mixers              -   [J]/[K]/[L]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 110, 0xffffff, \
	"Psycho mode (toggle)       -   [P]");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, x_pos, 120, 0xffffff, \
	"Switch fractal type        -   [A]/[D]");
}
