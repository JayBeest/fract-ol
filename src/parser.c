#include <stdio.h>
#include <libft.h>
#include <parser.h>

#define SAME 0

t_bool_err static	t_bool_true_no_err(void)
{
	t_bool_err	true_bool_no_error;

	true_bool_no_error.bool = TRUE;
	true_bool_no_error.error_nr = NO_ERROR;
	return (true_bool_no_error);
}

t_bool_err static	t_bool_false_err(t_err_no error_no)
{
	t_bool_err	false_bool_error_no;

	false_bool_error_no.bool = FALSE;
	false_bool_error_no.error_nr = error_no;
	if (error_no == NO_VALID_TYPE || error_no == NO_ARGS)
	{
		printf("Usage: fractal <fractal_type> [<example>] || ");
		printf("[<complex_pos>]\n");
		printf("\n    <fractal_type> :   'Mandelbrot'");
		printf("\n                       'Julia'");
		printf("\n                       'BurningShip'\n");
		printf("\n    <example> :        'Ex1'");
		printf("\n                       'Ex2'");
		printf("\n                       'Ex3'\n");
		printf("\n    <complex_pos> :    Real and imaginary component sepera");
		printf("ted by a space.");
		printf("\n                       Both roughly between -2 and +2.");
		printf("\n                       These will be used as 'C' values ");
		printf("calculating the Julia fractal\n");
	}
	return (false_bool_error_no);
}

t_bool_err static	parse_flag(int argc, const char **argv, t_scene *scene)
{
	static const char	*examples[3] = {"Ex1", "Ex2", "Ex3"};
	int					i;

	if (argc == 2)
		return (t_bool_true_no_err());
	i = 0;
	while (i < 3 && argc == 3)
	{
		if (ft_strlen(*argv) == 3 && ft_strncmp(examples[i], *argv, 3) == SAME)
			scene->setting = i;
		i++;
	}
	if (ft_strlen(argv[0]) < 15 && ft_strisfloat(argv[0]))
	{
		scene->julia.c.re = ft_atof(argv[0]);
		scene->setting = CUSTOM;
	}
	if (argc > 3 && ft_strlen(argv[1]) < 15 && ft_strisfloat(argv[1]))
		scene->julia.c.im = ft_atof(argv[1]);
	return (t_bool_true_no_err());
}

t_bool_err	parse_arguments(int argc, const char **argv, t_scene *scene)
{
	static const char	*fractal_type[3] = {"Mandelbrot", \
											"Julia", \
											"BurningShip"};
	unsigned int		arg_len;
	int					i;

	if (argc == 1)
		return (t_bool_false_err(NO_ARGS));
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
