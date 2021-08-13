#include "datatypes.h"

void    put_pixel(t_img_data *image, t_position position, unsigned int colour)
{
	char	*pixel_address;
	int		offset;

	offset = position.y * image->line_lenght + position.x * (image->bits_per_pixel / 8);
	pixel_address = image->img_address + offset;
	*(unsigned int *)pixel_address = colour;
}

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

