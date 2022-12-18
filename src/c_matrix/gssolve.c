#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double resid(int n, double a[n][n], double y[n], double x[n])
{
	double axsquare;
	for(int i = 0; i < n; i++)
	{
		double p = 0.0;
		for(int j = 0; j < n; j++)
		{
			p += a[i][j] * x[j];
		}
		axsquare += p*p;
	}
	return powf(axsquare, 0.5);
}

static double* gssolve(int n, double a[n][n], double y[n], double tol,  int maxiters)
{
	int iters = 0;
	double x[n];
	double p[n];
	for(int i = 0; i < n; i++)
	{
		x[i] = 1.0;
		p[i] = 1.0;
	}	
	double err = 10*tol;
	while(iters<maxiters && err>tol)
	{
		for(int i = 0; i < n; i++)
		{
			x[i] = y[i];
			for(int j = 0; j < n; j++)
			{
				if(i!=j){x[i] -= a[i][j]*p[j];}
				if(i>j){x[i] -= a[i][j]*x[j];}
				if(i<j){x[i] -= a[i][j]*p[j];}
			}
			x[i] /= a[i][i];
			
		}
		for(int i = 0; i < n; i++){p[i] = x[i];}
		err =  resid(n, a, y, x);
		iters++;
	}
	double* xptr;
	xptr = malloc(sizeof(double*)*n);
	double diff = 0;
	for(int i = 0; i < n; i++)
	{
		xptr[i] = x[i]+diff;
		diff*=-1;
		diff+=xptr[i];
	}
	return xptr;
}