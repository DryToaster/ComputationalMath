#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hadm.c"

int main()
{
	double** c;
	double a[19][4];
	double b[19][4];
	for (int i = 0; i < 19; i++)
	{
		a[i][0] = 1.0;
		a[i][1] = 3.0;
		a[i][2] = 5.0;
		a[i][3] = 7.0;
		b[i][0] = 2.0;
		b[i][1] = 4.0;
		b[i][2] = 8.0;
		b[i][3] = 16.0;
	}
	
	printf("    ");
	c = hadm(19,4,b,a);
	printf("%f\n", c[10][3]);

	for(int i = 0; i < 19; i++)
	{
		printf("\n");
		for(int j = 0; j < 4; j++)
		{
			printf("%f ", c[i][j]);
		}
	}
}