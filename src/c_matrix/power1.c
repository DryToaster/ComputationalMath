#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

static double power1(int n, double a[n][n], double tol, int maxiters)
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
        prodmv(n, a, xk, xk1);
        scaleToLast(n, xk1);
        err = error(n, xk, xk1);
        

        for (int i = 0; i < n; i++)
        {
            xk[i] = xk1[i];
        }
        
    }
    // Find lambda from rayleigh quotient

    prodmv(n, a, xk1, p);

    double num = dot(n, xk1, p);

    double denom = dot(n, xk1, xk1);

    double result = num / denom;
    return result;
}

