#ifndef HOOKS_H
# define HOOKS_H

# define KEY_RELEASE_MASK 1
# define BUTTON_PRESS_MASK 2
# define POINTER_MOTION_MASK 6
# define STRUCTURE_NOTIFY_MASK 17

# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define MOTION_NOTIFY 6
# define DESTROY_NOTIFY 17

void	hook_to_mlx(t_mlx *mlx);

#endif