#include "datatypes.h"

int mandelbrot(t_complex_position complex_position)
{
	int			iterations;
	double 		temp;
	t_complex 	c;
	t_complex 	z;

	c = complex_position.c;
	//	printf("c.real = %f\n", c.real);
	//	printf("c.i = %f\n", c.i);
	z = complex_position.z;
	iterations = 0;
	while (iterations < 30)
	{
		temp = z.real;
		z.real = z.real * z.real - z.i * z.i + c.real;
		z.i = 2 * temp * z.i + c.i;
		iterations++;
		if (z.real * z.real + z.i * z.i > 4)
			return (iterations);
	}
	return (0);
}

int julia(t_complex_position complex_position, t_complex julia)
{
	int			iterations;
	double 		temp;
	t_complex 	z;

	//	printf("c.real = %f\n", c.real);
	//	printf("c.i = %f\n", c.i);
	z = complex_position.z;
	iterations = 0;
	while (iterations < 30)
	{
		temp = z.real;
		z.real = temp * temp - z.i * z.i + julia.real;
		z.i = 2 * temp * z.i + julia.i;
		iterations++;
		if (z.real * z.real + z.i * z.i < 4)
			return (iterations);
	}
	return (0);
}