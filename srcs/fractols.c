#include "datatypes.h"

int mandelbrot(t_complex_position complex_position, int max_iterations)
{
	int			iterations;
	double 		temp;
	t_complex 	c;
	t_complex 	z;

	c = complex_position.c;
	//	printf("c.re = %f\n", c.re);
	//	printf("c.im = %f\n", c.im);
	z = complex_position.z;
	iterations = 0;
	while (iterations < max_iterations)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * temp * z.im + c.im;
		iterations++;
		if (z.re * z.re + z.im * z.im > 4)
			return (iterations);
	}
	return (0);
}

int julia(t_complex_position complex_position, t_complex julia)
{
	int			iterations;
	double 		temp;
	t_complex 	z;

	//	printf("c.re = %f\n", c.re);
	//	printf("c.im = %f\n", c.im);
	z = complex_position.z;
	iterations = 0;
	while (iterations < 30)
	{
		temp = z.re;
		z.re = temp * temp - z.im * z.im + julia.re;
		z.im = 2 * temp * z.im + julia.im;
		iterations++;
		if (z.re * z.re + z.im * z.im < 4)
			return (iterations);
	}
	return (30);
}