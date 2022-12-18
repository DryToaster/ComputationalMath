#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* prodmv(int m, int n, double a[m][n], double x[n])
{
	double* y;
	y = malloc(sizeof(double*)*m);
	for(int i = 0; i < m; i++)
	{
		y[i] = 0;

		for (int j = 0; j < n; j++)
		{
			y[i] += (a[i][j] * x[j]);
		}
	}
	return y;
}