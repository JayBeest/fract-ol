#include "../libft/libft.h"
#include "datatypes.h"
#include <stdio.h>

#define SAME 0

t_bool_err	t_bool_true_no_err()
{
	t_bool_err	true_bool_no_error;

	true_bool_no_error.bool = TRUE;
	true_bool_no_error.error_nr = NO_ERROR;
	return (true_bool_no_error);
}

t_bool_err	t_bool_false_err(t_err_no error_no)
{
	t_bool_err	false_bool_error_no;

	false_bool_error_no.bool = FALSE;
	false_bool_error_no.error_nr = error_no;
	return (false_bool_error_no);
}

t_bool_err parse_no_args()
{
	printf("Usage: fractal [-R <resolution>] [-C <complex_plane_pos>] [<fractal");
	printf("_type>] [<args>]\n");
	return (t_bool_true_no_err());
}

t_bool_err	parse_examples(int argc, const char **argv, int *arg_i, t_scene *scene)
{
	static const char	*example[3] = {"Ex1", "Ex2", "Ex3"};
	int 				i;
	printf("%d", scene->default_zoom);

	if (argc - 1 == *arg_i)
		return (t_bool_true_no_err());
	i = 0;
	while (i < 3)
	{
		if (ft_strlen(argv[*arg_i]) == 3 && ft_strncmp(example[i], argv[*arg_i], 3) == SAME)
		{
			printf("<<<< Load %s!!!\n", example[i]);
			return (t_bool_true_no_err());
		}
		i++;
	}
	return (t_bool_false_err(NOT_FRACTAL_TYPE));
}

t_bool_err	parse_fractal_args(int argc, const char **argv, int *arg_i, t_scene *scene)
{
	static const char	*fractal_type[2] = {"Mandelbrot", "Julia"};
	unsigned int 		arg_len;
	int 				i;

	arg_len = ft_strlen(argv[1]);
	i = 0;
	while (i < 2)
	{
		if (ft_strlen(fractal_type[i]) == arg_len && ft_strncmp(fractal_type[i], argv[*arg_i], arg_len) == SAME)
		{
			scene->current_fractal = i;
			return (parse_examples(argc, argv, arg_i, scene));
		}
		i++;
	}
	return (t_bool_false_err(NOT_FRACTAL_TYPE));
}

t_bool_err	parse_arguments(int argc, const char **argv, t_scene *scene)
{
//	static const char	*arguments[2] = {"-Z0", "-Re"};
	int 				i;

	i = 1;
	if (argc == 1)
	{
		return (parse_no_args());
	}
	else if (argc == 2 || argc == 3)
		return (parse_fractal_args(argc, argv, &i, scene));
//	else if (argc < 9)
//		parse_success = parse_flags(argc, argv, i, scene);

	return (t_bool_false_err(TOO_MANY_ARGS));
}
