#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* addv(int n, double a[n], double b[n])
{
	static double * c;
	c = malloc(sizeof(double*)*n);
	for (int i=0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}
	return c;
}
