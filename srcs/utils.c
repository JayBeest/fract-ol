#include "datatypes.h"
#include "main.h"

void	switch_bool(t_bool *bool)
{
	if (*bool)
		*bool = FALSE;
	else
		*bool = TRUE;
}

void	return_to_origin(t_scene *scene)
{
	scene->offset.x = 0;
	scene->offset.y = 0;
	scene->zoom = scene->default_zoom;
}

void	center_on_mouse(t_position mouse, t_scene *scene)
{
	scene->offset.x += mouse.x - (scene->res.x >> 1);
	scene->offset.y += mouse.y - (scene->res.y >> 1);
}

t_complex_position	pos_to_complex_pos(t_complex_plane plane, t_position pos)
{
	t_complex_position		complex_pos;

	complex_pos.c.re = pos.x * plane.step + plane.min.re;
	complex_pos.c.im = -pos.y * plane.step + plane.min.im;
	complex_pos.z.re = 0;
	complex_pos.z.im = 0;
	return (complex_pos);
}

t_complex_plane	calculate_complex_plane(t_scene scene)
{
	t_complex_plane	plane;

	plane.min.re = (scene.offset.x - RESOLUTION_X / 2) / scene.zoom;
	plane.max.re = plane.min.re + RESOLUTION_X / scene.zoom;
	plane.step = (plane.max.re - plane.min.re) / RESOLUTION_X;
	plane.min.im = -(scene.offset.y - RESOLUTION_Y / 2) / scene.zoom;
	plane.max.im = plane.min.im - RESOLUTION_Y / scene.zoom;
	return (plane);
}
