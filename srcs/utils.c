#include "datatypes.h"

#include <stdio.h>

unsigned int fetch_colour(int n)
{
	unsigned int		colour;
	static unsigned int test_colour;

	test_colour++;
	colour = 0xe21515 + 40 * n;
	if (n == 0)
		return (0x000000);
	if (n > 18)
		colour = 0x22ff2f + 5 * n;
	return (colour );
	return (test_colour);
}

void return_to_origin(t_scene *scene)
{
	scene->offset.x = -100;
	scene->offset.y = 0;
}

void center_on_mouse(t_position mouse, t_scene *scene)
{
	scene->offset.x += mouse.x - (scene->res.x >> 1);
	scene->offset.y += mouse.y - (scene->res.y >> 1);
}