#include "datatypes.h"
#include "main.h"
#include "utils.h"
#include "draw.h"

void key_action_controls(t_scene *scene, t_key key_code)
{
	if (key_code == LEFT)
		scene->offset.x -= STEP;
	else if (key_code == RIGHT)
		scene->offset.x += STEP;
	else if (key_code == DOWN)
		scene->offset.y += STEP;
	else if (key_code == UP)
		scene->offset.y -= STEP;
	else if (key_code == D && scene->current_fractal < SHIP)
		scene->current_fractal++;
	else if (key_code == A && scene->current_fractal > MANDELBROT)
		scene->current_fractal--;
}

void key_action_settings(t_scene *scene, t_key key_code)
{
	if (key_code == PLUS && scene->iteration_amount < 1000)
		scene->iteration_amount += 10;
	else if (key_code == MIN && scene->iteration_amount > 10)
		scene->iteration_amount -= 10;
	else if (key_code == B_SPACE)
		return_to_origin(scene);
	else if (key_code == M)
		switch_bool(&scene->zoom_to_mouse);
	else if (key_code == N)
		switch_bool(&scene->julia_animation);
	else if (key_code == Z)
		scene->julia = position_to_complex_position(scene->plane, scene->mouse);
}

void key_action_colours(t_scene *scene, t_key key_code)
{
	if (key_code == J)
		scene->colours.colour_mixer_1 += 1;
	else if (key_code == K)
		scene->colours.colour_mixer_2 += 5;
	else if (key_code == L)
		scene->colours.colour_mixer_2++;
	else if (key_code == P)
		switch_bool(&scene->psycho);
}

//void key_action_menu(t_scene *scene, t_key key_code)
//{
//}
