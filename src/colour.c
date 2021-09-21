#include <datatypes.h>

unsigned int	rgb_to_hex(unsigned char r, unsigned char g, unsigned char b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b + 0xff));
}

unsigned int	fetch_colour(unsigned int n, t_colours colours, \
	unsigned int max_iterations)
{
	unsigned int	test_colour;
	unsigned int	n_mod;
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
