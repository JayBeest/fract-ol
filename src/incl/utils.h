#ifndef UTILS_H
# define UTILS_H

# include <datatypes.h>

void				return_to_origin(t_scene *scene);
void				center_on_mouse(t_position mouse, t_scene *scene);
void				switch_bool(t_bool *bool);
t_complex_position	pos_to_complex_pos(t_complex_plane plane, t_position pos);
t_complex_plane		calculate_complex_plane(t_scene scene);

#endif
