#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* hadv(int n, double u[n], double v[n])
{
	double* w;
	w = malloc(sizeof(double*)*n);
	for(int i = 0; i < n; i++)
	{
		w[i] = u[i]*v[i];
	}	
	return w;
}