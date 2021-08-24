#include "datatypes.h"

int mandelbrot(t_scene scene)
{
	int			iterations;
	long double temp;
	t_complex 	c;
	t_complex 	z;

	c = scene.complex_position.c;
	z = scene.complex_position.z;
	iterations = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iterations < scene.iteration_amount)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * temp * z.im + c.im;
		iterations++;
	}
	return (iterations);
}

int julia(t_scene scene)
{
	int			iterations;
	long double temp;
	t_complex 	z;
	t_complex 	c;

	z = scene.complex_position.c;
	c = scene.julia;
	iterations = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iterations < scene.iteration_amount)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * temp * z.im + c.im;
		iterations++;
	}
	return (iterations);
}