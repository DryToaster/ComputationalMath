#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* jacobisolve(int n, double a[n][n], double y[n], double tol, int maxiters)
{
	double* x;
	x = malloc(sizeof(double*)*n);
	double dinverse[n];
	double lu[n][n];
	
	for(int i = 0; i < n; i++)
	{
		x[i] = 1.0;
		dinverse[i] = 1.0/a[i][i];	
		for(int j = 0; j < n; j++)
		{	
			if(i!=j){ lu[i][j] = a[i][j]; }
			else{ lu[i][j] = 0; }
		}	
	}
	
	int iters = 0;
	double err = 10.0 * tol;
	
	while(err>tol && iters<maxiters)
	{
		
		iters++;
		double lux[n];
		double y_lux[n];
		
		for(int i = 0; i < n; i++)
		{	
			lux[i] = 0;
			for(int j = 0; j < n; j++)
			{
				lux[i] += (lu[i][j] * x[j]);
				
			}
			y_lux[i] = y[i] - lux[i];
		}
 
		double x1[n];
		err = 0.0;

		for(int i = 0; i < n; i++)
		{
			x1[i] = dinverse[i] * y_lux[i];
			err += fabs(x1[i] - x[i]);
			x[i] = x1[i];
		}
	}
	return x;
}