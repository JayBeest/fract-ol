#ifndef FRACTOL_H
# define FRACTOL_H
# include <X11/Xlib.h>

# define PROJECT "Fract'ol"
# define DEFAULT_RES_X 1024
# define DEFAULT_RES_Y 768
# define DEFAULT_ZOOM 4
# define STEP 15
# define ZOOM_STEP 1


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