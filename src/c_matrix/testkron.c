#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kronm.c"

int main()
{
	double a[2][3] = {{1.0,2.0,3.0},{4.0,5.0,6.0}};
	double b[3][3] = {{1.0,2.0,3.0},{5.0,6.0,7.0},{10.0,10.0,10.0}};

	double** c;
	c=kronm(2, 3, 3, 3, a, b);
	printf("	\n");
	for(int i = 0; i < 6; i++)
	{	printf("\n");
		for(int j = 0; j < 9; j++)
		{
			printf("%f|",c[i][j]);
		}
	}
	return 0;
}