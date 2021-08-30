#ifndef DATA_TYPES_H
# define DATA_TYPES_H


typedef enum
{
	FALSE,
	TRUE
}			t_bool;

typedef enum
{
	NO_ERROR = 0,
	NO_VALID_TYPE = 1,
	TOO_MANY_ARGS = 2
}			t_err_no;

typedef enum
{
	MANDELBROT,
	JULIA,
	SHIP
}			t_fractol_type;

typedef enum
{
	EX1,
	EX2,
	EX3,
	DEFAULT
}			t_setting;

typedef enum
{
	MACOS = 0,
	LINUX = 1
}			t_arch;

typedef enum
{
	A = 0,
	C = 8,
	D = 2,
	S = 1,
	W = 13,
	M = 46,
	N = 45,
	P = 35,
	J = 38,
	K = 40,
	L = 37,
	Z = 6,
	PLUS = 24,
	MIN = 27,
	DOWN = 125,
	UP = 126,
	LEFT = 123,
	RIGHT = 124,
	B_SPACE = 51,
	ESC = 53
}			t_key;

typedef struct
{
	t_bool		bool;
	t_err_no	error_nr;
}			t_bool_err;

typedef struct
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}			t_rgb;

typedef struct
{
	int		iterations;
	t_rgb	colour;
}			t_;

typedef struct
{
	int	colour_mixer_1;
	int colour_mixer_2;
	int colour_mixer_3;
}			t_colours;

typedef struct
{
	long double re;
	long double im;
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
	long double x;
	long double y;
}			t_grid_position;

typedef struct
{
	t_complex	min;
	t_complex	max;
	long double	step;
}			t_complex_plane;

typedef struct
{
	void	*img_ptr;
	char	*img_address;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}			t_img_data;

typedef struct s_scene
{
	t_resolution			res;
	t_fractol_type			current_fractal;
	int 					iteration_amount;
	t_bool					zoom_to_mouse;
	t_complex_plane			plane;
	t_grid_position			offset;
	t_position				mouse;
	t_complex_position		julia;
	t_bool					julia_animation;
	t_bool					psycho;
	t_colours				colours;
	t_setting				setting;
	//debug
	t_position				grid_position;
	t_complex_position		complex_position;
	int						n;
	long double				zoom;
	int 					default_zoom;
}		t_scene;

typedef void(*t_action_function)(t_scene*, t_key key, t_position position);

typedef struct
{
	t_action_function	action[128];
}		t_action_list;

typedef struct
{
	void					*mlx_ptr;
	void					*mlx_window;
//	t_pixel					**pixels;
	t_scene					scene;
	t_action_list			action_list;
	t_img_data				image;
}		t_mlx;

typedef int(*t_fractal_f_ptr)(t_scene);

#endif
