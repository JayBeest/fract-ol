#include "datatypes.h"
#include "main.h"
#include <stdio.h>

void switch_bool(t_bool *bool)
{
	if (*bool)
		*bool = FALSE;
	else
		*bool = TRUE;
}

unsigned int rgb_to_hex(unsigned char r, unsigned char g, unsigned char b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b + 0xff));
}

unsigned int fetch_colour(int n, t_colours colours, int max_iterations)
{
	unsigned int	test_colour;

	if (n == max_iterations)
		return (0x000000);
	test_colour = rgb_to_hex(colours.colour_mixer_1 * n, colours.colour_mixer_2 * n, colours.colour_mixer_3 * n);
	return (test_colour);
}

unsigned int fetch_colour2(int n, t_colours colours, int max_iterations)
{
	unsigned int		colour;

	if (n == max_iterations)
		return (0x000000);
	colour = (0xe21515 + colours.colour_mixer_1 * n) / colours.colour_mixer_3;
	if (n > 18)
		colour = (0x22ff2f + colours.colour_mixer_2 * n) / colours.colour_mixer_3;
	return (colour);
}

unsigned int fetch_colour3(int n, t_colours colours, int max_iterations)
{
	unsigned int	test_colour;
	int 			n_mod;
	t_rgb			rgb_c;

	if (n == max_iterations)
		return (0x000000);
	n_mod = (n % (max_iterations >> 1));
	rgb_c.r = colours.colour_mixer_3 * n_mod;
	rgb_c.g = colours.colour_mixer_2 * n_mod;
	rgb_c.b = colours.colour_mixer_1 * n_mod;
	test_colour = rgb_to_hex(rgb_c.r, rgb_c.g, rgb_c.b);
	return (test_colour);
}

void return_to_origin(t_scene *scene)
{
	scene->offset.x = 0;
	scene->offset.y = 0;
	scene->zoom = scene->default_zoom;
}

void center_on_mouse(t_position mouse, t_scene *scene)
{
		scene->offset.x += mouse.x - (scene->res.x >> 1);
		scene->offset.y += mouse.y - (scene->res.y >> 1);
}

void zoom_out(t_scene *scene, t_position mouse)
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
void zoom_in(t_scene *scene, t_position mouse)
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