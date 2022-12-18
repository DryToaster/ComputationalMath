#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gssolve.c"

int main()
{
	printf("start\n");
	double sis[5][5] = {{2.0,0.0,0.0,0.0,0.0},{1.0,1.0,0.0,0.0,0.0},{1.0,1.0,1.0,0.0,0.0},{1.0,1.0,1.0,1.0,0.0},{1.0,1.0,1.0,1.0,1.0}};
	double y[5] = {69.0,2.0,30.0,3.0,5.0};
	double* soln;
	printf("initialized\n");
	soln = gssolve(5, sis, y, .0001, 200);
	printf("solved\n");
	for(int i = 0; i < 5; i++)
	{
		printf("%f\n", soln[i]);
	}
}