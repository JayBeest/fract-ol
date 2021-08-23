#ifndef DRAW_H
#define DRAW_H

int 	draw_fractal_to_image(t_mlx *mlx);
int		redraw_image(t_mlx *mlx);
void	calculate_complex_position(t_scene *complex, t_position pos);
void	put_pixel(t_img_data *image, t_position position, unsigned int colour);
void	calculate_complex_plane(t_scene *scene);

#endif