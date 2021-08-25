#ifndef DRAW_H
#define DRAW_H

int					draw_fractal_to_image(t_mlx *mlx);
int					redraw_window(t_mlx *mlx);
t_complex_position	position_to_complex_position(t_complex_plane plane, t_position pos);
void				put_pixel(t_img_data *image, t_position position, unsigned int colour);
t_complex_plane		calculate_complex_plane(t_scene scene);

#endif