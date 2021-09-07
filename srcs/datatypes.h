#ifndef DATATYPES_H
# define DATATYPES_H
# define PROJECT "Fract'ol"
# define RESOLUTION_X 800
# define RESOLUTION_Y 600
# define OFFSET_STEP 15
# define ZOOM_FACTOR 1.5
# define DEFAULT_ITERATIONS 50
# define MANDEL_X_RATIO	4
# define MANDEL_Y_RATIO	7

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef enum e_err_no
{
	NO_ERROR = 0,
	NO_VALID_TYPE = 1
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
	DEFAULT = 0
}			t_setting;

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
