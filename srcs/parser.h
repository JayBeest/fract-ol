#ifndef PARSER_H
#define PARSER_H

t_bool_err	parse_fractal_args(int argc, const char **argv, int *arg_i, t_scene *scene);
t_bool_err	parse_arguments(int argc, const char **argv, t_scene *scene);
t_bool_err	parse_examples(int argc, const char **argv, int *arg_i, t_scene *scene);
t_bool_err	t_bool_false_err(t_err_no error_no);
t_bool_err	t_bool_true_no_err();


#endif
