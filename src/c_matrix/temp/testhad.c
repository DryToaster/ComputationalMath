#include <stdio.h>
#include <stdlib.h>
#include "hadv.c"

int main()
{
	double a[5] = {1.0,2.0,3.0,4.0,5.0};	
	double b[5] = {5.0,4.0,3.0,2.0,1.0};
	double* c;
	c = hadv(5, a, b);
	for(int i = 0; i < 5; i++)
	{
		printf("%f\n", c[i]);
	}
}