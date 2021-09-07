#ifndef DRAW_H
# define DRAW_H

int		draw_fractal_to_image(t_mlx *mlx);
void	redraw_window(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, t_position position, unsigned int colour);

#endif