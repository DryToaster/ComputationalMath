#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* crossv(double a[3], double b[3])
{
	static double * c;
	c = malloc(sizeof(double*));
	
	c[0] = b[3]*a[2] - a[3]*b[2];
	c[1] = b[1]*a[3] - a[1]*b[3];
	c[2] = b[2]*a[1] - a[2]*b[1];
	return c;
}
