#ifndef UTILS_H
# define UTILS_H

unsigned int	fetch_colour(int n);
void return_to_origin(t_scene *scene);
void center_on_mouse(t_position mouse, t_scene *scene);
void zoom_in(t_scene *scene, t_position mouse);
void zoom_out(t_scene *scene, t_position mouse);

#endif
