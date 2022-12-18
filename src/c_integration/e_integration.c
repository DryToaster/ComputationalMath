#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trapezoidOMP.c"
double f(double x)
{
	return 1.0/x;
}

int main()
{	
	double x0 = 2.5;
	double sum = 0.0;
	while (sum<1.0)
	{
		x0 +=.0001;		
		sum = trapezoidOMP(f, 1.0, x0, 20000);
	}
	
	printf("e approximation: %f", x0);

	return 0;
}