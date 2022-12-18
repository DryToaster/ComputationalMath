#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* subv(int size, double a[size], double b[size])
{
	static double * c;
	c = malloc(sizeof(double*)*size);
	for (int i=0; i < size; i++)
	{
		c[i] = a[i] - b[i];
	}
	return c;
}
