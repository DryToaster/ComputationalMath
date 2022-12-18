#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double trapezoid(double (*f)(), double a, double b, int n)
{
	double h = (b - a) / (float)n;
	
	int iters = 1;

	double sum = (f(a)+f(b))/2.0;
	
	double x_1 = a + h;

	for (int i = 0; i < n; i++)
	{
		sum += f(x_1 + (i)*h);
	}

	
	return sum*h;
}

static double simpsons(double (*f)(), double a, double b, int n)
{
	int i = 2*n + 1;
	double h = (b-a)/(float)i;
	
	double sum = (f(a)+f(b)+4.0*f(b-h))/3.0;
	int iters = 0;	
	double halfsum = 0.0;
	double qrtrsum = 0.0;
	double x = a + h;
	while (iters < (n-1)/2)
	{
		qrtrsum += f(x);
		halfsum += f(h+h);
		
		x += 2.0*h;
		iters++;
	}
	return sum*h;
}


