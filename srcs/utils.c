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

unsigned int fetch_colour(int n, t_colours colours)
{
	unsigned int		colour;
	static unsigned int test_colour;

	test_colour = rgb_to_hex(colours.colour_mixer_1 * n, colours.colour_mixer_2 * n, colours.colour_mixer_3 * n);
	colour = (0xe21515 + colours.colour_mixer_1 * n) / colours.colour_mixer_3;
	if (n == 0)
		return (0x000000);
	if (n > 18)
		colour = (0x22ff2f + colours.colour_mixer_2 * n) / colours.colour_mixer_3;
	return (test_colour);
	return (colour);
}

void return_to_origin(t_scene *scene)
{
	scene->offset.x = 0;
	scene->offset.y = 0;
}

void center_on_mouse(t_position mouse, t_scene *scene)
{
		scene->offset.x += mouse.x - (scene->res.x >> 1);
		scene->offset.y += mouse.y - (scene->res.y >> 1);
}

void zoom_in(t_scene *scene, t_position mouse)
{
	scene->zoom = scene->zoom * ZOOM_FACTOR;
	if (scene->zoom_to_mouse)
	{
		scene->offset.x = (scene->offset.x + mouse.x - (scene->res.x >> 1)) * ZOOM_FACTOR;
		scene->offset.y = (scene->offset.y + mouse.y - (scene->res.y >> 1)) * ZOOM_FACTOR;
	}
	else
	{
		scene->offset.x = scene->offset.x * ZOOM_FACTOR;
		scene->offset.y = scene->offset.y * ZOOM_FACTOR;
	}
}
void zoom_out(t_scene *scene, t_position mouse)
{

	scene->zoom = scene->zoom / ZOOM_FACTOR;
	if (scene->zoom_to_mouse)
	{
		scene->offset.x = (scene->offset.x + mouse.x - (scene->res.x >> 1)) / ZOOM_FACTOR;
		scene->offset.y = (scene->offset.y + mouse.y - (scene->res.y >> 1)) / ZOOM_FACTOR;
	}
	else
	{
		scene->offset.x = scene->offset.x / ZOOM_FACTOR;
		scene->offset.y = scene->offset.y / ZOOM_FACTOR;
	}
}