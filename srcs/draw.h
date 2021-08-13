#ifndef DRAW_H
#define DRAW_H

int 	draw_fractal_to_image(t_mlx *mlx);
int		redraw_image(t_mlx *mlx);
void	calculate_complex_position(t_scene *scene, t_position pos);


#endif