#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 12
static double** kronm(int m, int n, int w, int u, double a[m][n], double b[w][u])
{
	omp_set_num_threads(NUM_THREADS);
	double** c;
	c = malloc(sizeof(double*)*m*w);
	for(int i = 0; i < 6; i++)
	{
		c[i] = malloc(sizeof(double*)*n*u);
	}
	printf("        \n");
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("\n");
			#pragma omp parallel
			{
			int count = omp_get_num_threads();
			int id = omp_get_thread_num();
			for(int x = id; x < w; x+=count)
			{	
				for(int y = 0; y < u; y++)
				{
					c[w*i+x][u*j+y] = a[i][j] * b[x][y];
				}
			}
			}
		}
	}
	
	return c;
}