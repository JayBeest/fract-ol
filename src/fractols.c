#include <datatypes.h>

int	mandelbrot(t_scene scene)
{
	int			iterations;
	t_complex	z;
	t_complex	c;
	t_complex	squared;

	c = scene.complex_position.c;
	z = scene.complex_position.z;
	squared.re = 0;
	squared.im = 0;
	iterations = 0;
	while (squared.re + squared.im <= 4 && iterations < scene.iteration_amount)
	{
		z.im = 2 * z.re * z.im + c.im;
		z.re = squared.re - squared.im + c.re;
		squared.re = z.re * z.re;
		squared.im = z.im * z.im;
		iterations++;
	}
	return (iterations);
}

int	julia(t_scene scene)
{
	int			iterations;
	t_complex	z;
	t_complex	c;
	t_complex	squared;

	z = scene.complex_position.c;
	c = scene.julia.c;
	squared.re = z.re * z.re;
	squared.im = z.im * z.im;
	iterations = 0;
	while (squared.re + squared.im <= 4 && iterations < scene.iteration_amount)
	{
		z.im = 2 * z.re * z.im + c.im;
		z.re = squared.re - squared.im + c.re;
		squared.re = z.re * z.re;
		squared.im = z.im * z.im;
		iterations++;
	}
	return (iterations);
}

int	burning_ship(t_scene scene)
{
	int			iterations;
	t_complex	c;
	t_complex	z;
	t_complex	squared;

	c = scene.complex_position.c;
	c.im = -1 * c.im;
	z.im = -1 * z.im;
	z = scene.complex_position.z;
	squared.re = 0;
	squared.im = 0;
	iterations = 0;
	while (squared.re + squared.im <= 4 && iterations < scene.iteration_amount)
	{
		z.im = 2 * z.re * z.im;
		if (z.im < 0)
			z.im = -z.im;
		z.im += c.im;
		z.re = squared.re - squared.im + c.re;
		squared.re = z.re * z.re;
		squared.im = z.im * z.im;
		iterations++;
	}
	return (iterations);
}
