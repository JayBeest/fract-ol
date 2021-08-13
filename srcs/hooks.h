#ifndef HOOKS_H
#define HOOKS_H

int	kill(t_mlx *mlx);
int mouse_button(int button, int x, int y, t_mlx *mlx);
int mouse_move(int x, int y, t_mlx *mlx);
int	keypress(t_key key_code, t_mlx *mlx);


#endif