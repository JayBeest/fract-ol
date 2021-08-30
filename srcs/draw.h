#ifndef DRAW_H
#define DRAW_H

int 				draw_fractal_to_image(t_mlx *mlx);
void				redraw_window(t_mlx *mlx);
t_complex_position	pos_to_complex_pos(t_complex_plane plane, t_position pos);
void				put_pixel(t_mlx *mlx, t_position position, unsigned int colour);
t_complex_plane		calculate_complex_plane(t_scene scene);

#endif