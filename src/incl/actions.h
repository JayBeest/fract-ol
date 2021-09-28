#ifndef ACTIONS_H
# define ACTIONS_H

# include <datatypes.h>

void	key_action_controls(t_scene *scene, t_key key);
void	key_action_settings(t_scene *scene, t_key key);
void	key_action_colours(t_scene *scene, t_key key);
void	zoom_out(t_scene *scene, t_position mouse);
void	zoom_in(t_scene *scene, t_position mouse);

#endif
