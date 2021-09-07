#ifndef DATATYPES_H
# define DATATYPES_H

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef enum e_err_no
{
	NO_ERROR,
	NO_VALID_TYPE,
	NO_ARGS
}			t_err_no;

typedef enum e_fractol_type
{
	MANDELBROT,
	JULIA,
	SHIP
}			t_fractol_type;

typedef enum e_setting
{
	EX1,
	EX2,
	EX3,
	DEFAULT
}			t_setting;

# ifdef __linux__

typedef enum e_key
{
	A = 97,
	D = 100,
	S = 115,
	W = 119,
	M = 109,
	N = 110,
	P = 112,
	J = 106,
	K = 107,
	L = 108,
	Z = 122,
	F1 = 65470,
	PLUS = 61,
	MIN = 45,
	DOWN = 65364,
	UP = 65362,
	LEFT = 65361,
	RIGHT = 65363,
	B_SPACE = 65288,
	ESC = 65307
}			t_key;

# else

typedef enum e_key
{
	A = 0,
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
	F1 = 122,
	PLUS = 24,
	MIN = 27,
	DOWN = 125,
	UP = 126,
	LEFT = 123,
	RIGHT = 124,
	B_SPACE = 51,
	ESC = 53
}			t_key;

# endif

typedef struct s_bool_err
{
	t_bool		bool;
	t_err_no	error_nr;
}			t_bool_err;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}			t_rgb;

typedef struct s_colours
{
	int	colour_mixer_1;
	int	colour_mixer_2;
	int	colour_mixer_3;
}			t_colours;

typedef struct s_complex
{
	long double	re;
	long double	im;
}			t_complex;

typedef struct s_resolution
{
	int	x;
	int	y;
}			t_resolution;

typedef struct s_position
{
	int	x;
	int	y;
}			t_position;

typedef struct s_complex_position
{
	t_complex	c;
	t_complex	z;
}			t_complex_position;

typedef struct s_grid_position
{
	long double	x;
	long double	y;
}			t_grid_position;

typedef struct s_complex_plane
{
	t_complex	min;
	t_complex	max;
	long double	step;
}			t_complex_plane;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*img_address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_scene
{
	t_resolution			res;
	t_fractol_type			current_fractal;
	int						iteration_amount;
	t_bool					zoom_to_mouse;
	t_complex_plane			plane;
	t_grid_position			offset;
	t_position				mouse;
	t_complex_position		julia;
	t_bool					julia_animation;
	t_bool					control_menu;
	t_bool					psycho;
	t_colours				colours;
	t_setting				setting;
	t_complex_position		complex_position;
	int						n;
	long double				zoom;
	int						default_zoom;
}		t_scene;

typedef struct s_mlx
{
	void					*mlx_ptr;
	void					*mlx_window;
	t_scene					scene;
	t_img_data				image;
}		t_mlx;

typedef int(*t_fractal_f_ptr)(t_scene);

#endif
