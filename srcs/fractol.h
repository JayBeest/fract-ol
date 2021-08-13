#ifndef FRACTOL_H
# define FRACTOL_H
# include <X11/Xlib.h>
# include "../libft/libft.h"

# define PROJECT "Fract'ol"
# define DEFAULT_RES_X 800
# define DEFAULT_RES_Y 600
# define DEFAULT_ZOOM 4
# define STEP 15
# define ZOOM_FACTOR 1.1


typedef enum
{
	FALSE = 0,
	TRUE = 1
}			t_bool;

typedef enum
{
	JULIA = 1,
	MANDELBROT = 2
}			t_fractal_type;

typedef enum
{
	A = 0,
	D = 2,
	S = 1,
	W = 13,
	ESC = 53
}			t_key;

typedef struct
{
	double real;
	double i;
}			t_complex;

typedef struct
{
	int x;
	int y;
}			t_resolution;

typedef struct
{
	int x;
	int y;
}			t_position;

typedef struct
{
	t_complex	c;
	t_complex	z;
}			t_complex_position;

typedef struct
{
	double x;
	double y;
}			t_grid_position;

typedef struct
{
	void	*img_ptr;
	char	*img_address;
	int 	bits_per_pixel;
	int 	line_lenght;
	int 	endian;
}			t_img_data;

typedef struct
{
	t_resolution 	res;
	t_fractal_type	current_fractal;
	t_position 		offset;
	t_position		mouse;
	//debug
	t_grid_position grid_position;
	t_complex_position complex_position;
	int n;
	double 			zoom;
}		t_scene;

typedef struct
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_scene		scene;
	t_img_data	image;
}		t_mlx;

void	init_default_scene(t_scene *scene);
void	init_scene(t_scene *scene);

#endif