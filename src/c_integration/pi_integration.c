#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trapezoidOMP.c"
double f(double x)
{
	return 4.0*powf(1.0-powf(x,2.0), 0.5);
}

int main()
{
	double piApp = trapezoidOMP(f, 0.0, 1.0, 20000);
	printf("Pi approximation: %f", piApp);

	return 0;
}