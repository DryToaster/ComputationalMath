#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double** kronm(int m, int n, int w, int u, double a[m][n], double b[w][u])
{
	double** c;
	c = malloc(sizeof(double*)*6);
	for(int i = 0; i < 6; i++)
	{
		c[i] = malloc(sizeof(double*)*12);
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("\n");
			for(int x = 0; x < w; x++)
			{	
				for(int y = 0; y < u; y++)
				{
					c[w*i+x][u*j+y] = a[i][j] * b[x][y];
				}
			}
		}
	}
	
	return c;
}