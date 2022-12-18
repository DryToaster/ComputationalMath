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

static void jacobisolve(int n, double a[n][n], double y[n], double x[n], double tol, int maxiters)
{
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
		
		for(int i = 0; i < n; i++)
		{
			x1[i] = dinverse[i] * y_lux[i];
			x[i] = x1[i];
		}
		err = resid(n, a, y, x);
	}
}
static void prodmv(int n, double a[n][n], double b[n], double x[n])
// x += Ab
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i] += a[i][j] * b[j];
        }
    }
}

static double dot(int n, double a[n], double b[n])
{
    double p = 0;
    for (int i = 0; i < n; i++)
    {
        p += a[i] * b[i];
    }
    return p;
}

static void scaleToLast(int n, double v[n])
{
    for (int i = 0; i < n; i++)
    {
        v[i] /= v[n - 1];
    }
}

static double error(int n, double u[n], double v[n])
{
    double err = 0.0;
    for (int i = 0; i < n; i++)
    {
        err += fabs(u[i] - v[i]);
    }
    return err;
}

static double inversepower(int n, double a[n][n], double tol, int maxiters)
{
    double err = 10.0*tol;
    int iters = 0;
    //double x0[n], double x1[n], double q0[n], 
    
    double xk[n];
    double xk1[n];
    double p[n];
    for(int i = 0; i < n; i++)
    {
	xk[i] = 1.0;
    }
    
    while(err>tol && iters<maxiters)
    {
        
        iters++;
        jacobisolve(n, a, xk, xk1, tol, 20);
        
        scaleToLast(n, xk1);
        for(int i = 0; i < 1; i++){}

        err = error(n, xk, xk1);
        

        for (int i = 0; i < n; i++)
        {
            xk[i] = xk1[i];
        }
        
    }

    prodmv(n, a, xk1, p);
    for(int i = 0; i < 1; i++)
    {
    }
    double num = dot(n, xk1, p);
    //printf("\naxkxk\n");
    for(int i = 0; i < 1; i++)
    { 
    }
    double denom = dot(n, xk1, xk1);
    double result = denom/num;
    return result;
}

