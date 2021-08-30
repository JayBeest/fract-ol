#include "../libft/libft.h"
#include "datatypes.h"
#include <stdio.h>

#define SAME 0

t_bool_err	t_bool_true_no_err(void)
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

t_bool_err	parse_no_args(void)
{
	printf("Usage: fractal [<fractal_type>] [<example>]\n");
	printf("");
	return (t_bool_true_no_err());
}

t_bool_err	parse_flag(int argc, const char **argv, t_scene *scene)
{
	static const char	*examples[3] = {"Ex1", "Ex2", "Ex3"};
	int					i;

	i = 0;
	while (i < 3 && argc == 3)
	{
		if (ft_strlen(*argv) == 3 && ft_strncmp(examples[i], *argv, 3) == SAME)
		{
			scene->setting = i;
			printf("example: %s\n", examples[i]);
		}
		i++;
	}
	return (t_bool_true_no_err());
}

t_bool_err	parse_arguments(int argc, const char **argv, t_scene *scene)
{
	static const char	*fractal_type[3] = {"Mandelbrot", "Julia", "Ship"};
	unsigned int		arg_len;
	int					i;

	if (argc == 1)
		return (parse_no_args());
	arg_len = ft_strlen(argv[1]);
	i = 0;
	while (i < 3)
	{
		if (ft_strlen(fractal_type[i]) == arg_len && \
			ft_strncmp(fractal_type[i], argv[1], arg_len) == SAME)
		{
			scene->current_fractal = i;
			return (parse_flag(argc, argv + 2, scene));
		}
		i++;
	}
	return (t_bool_false_err(NO_VALID_TYPE));
}
