#include <defines.h>
#include <datatypes.h>
#include <utils.h>

void	key_action_controls(t_scene *scene, t_key key_code)
{
	if (key_code == LEFT)
		scene->offset.x -= OFFSET_STEP;
	else if (key_code == RIGHT)
		scene->offset.x += OFFSET_STEP;
	else if (key_code == DOWN)
		scene->offset.y += OFFSET_STEP;
	else if (key_code == UP)
		scene->offset.y -= OFFSET_STEP;
	else if (key_code == D && scene->current_fractal < SHIP)
		scene->current_fractal++;
	else if (key_code == A && scene->current_fractal > MANDELBROT)
		scene->current_fractal--;
}

void	key_action_settings(t_scene *scene, t_key key_code)
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
		scene->julia = pos_to_complex_pos(scene->plane, scene->mouse);
	else if (key_code == F1)
		switch_bool(&scene->controls_menu);
	else if (key_code == F2)
		switch_bool(&scene->info_menu);
}

void	key_action_colours(t_scene *scene, t_key key_code)
{
	if (key_code == J)
		scene->colours.colour_mixer_1++;
	else if (key_code == K)
		scene->colours.colour_mixer_2++;
	else if (key_code == L)
		scene->colours.colour_mixer_3++;
	else if (key_code == P)
		switch_bool(&scene->psycho);
}

void	zoom_out(t_scene *scene, t_position mouse)
{
	if (scene->zoom_to_mouse)
	{
		scene->offset.x = scene->offset.x + mouse.x - (scene->res.x >> 1);
		scene->offset.y = scene->offset.y + mouse.y - (scene->res.y >> 1);
	}
	scene->offset.x = scene->offset.x * ZOOM_FACTOR;
	scene->offset.y = scene->offset.y * ZOOM_FACTOR;
	scene->zoom = scene->zoom * ZOOM_FACTOR;
}

void	zoom_in(t_scene *scene, t_position mouse)
{
	if (scene->zoom_to_mouse)
	{
		scene->offset.x = scene->offset.x + mouse.x - (scene->res.x >> 1);
		scene->offset.y = scene->offset.y + mouse.y - (scene->res.y >> 1);
	}
	if (scene->zoom > scene->default_zoom)
	{
		scene->offset.x = scene->offset.x / ZOOM_FACTOR;
		scene->offset.y = scene->offset.y / ZOOM_FACTOR;
		scene->zoom = scene->zoom / ZOOM_FACTOR;
	}
}
