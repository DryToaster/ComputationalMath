#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* scalev(int n, double a, double b[n])
{
	static double * c;
	c = malloc(sizeof(double*)*n);
	for (int i=0; i < n; i++)
	{
		c[i] = a * b[i];
	}
	return c;
}
