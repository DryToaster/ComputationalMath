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

static void gssolve(int n, double a[n][n], double y[n], double x[n], double tol,  int maxiters)
{
	int iters = 0;
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

static double inversepowerg(int n, double a[n][n], double tol, int maxiters)
{
    double err = 10.0*tol;
    int iters = 0; 
    
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
        gssolve(n, a, xk, xk1, tol, 20);
        
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
