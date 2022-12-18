#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 12

static double dot(int n, double a[n], double b[n])
{
	double c;
	c = 0;
	for (int i=0; i < n; i++)
	{
		c += a[i] * b[i];
		//printf("multiplicating %f and %f\n", a[i], b[i]);
	}
	//printf("result: %f\n", c);
	return c;
}


static double** prodmOMP(int m, int n, int p, double a[m][n], double b[n][p])
{
	double **c;
	c = malloc(sizeof(double*)*m);
	printf("    \n");

	for(int i = 0; i < m; i++)
	{
		c[i] = malloc(sizeof(double*)*p);
	}

	omp_set_num_threads(NUM_THREADS);

	
      for (int i = 0; i < m; i++) {
	    #pragma omp parallel
	    {
		  int id = omp_get_thread_num();
              int count = omp_get_num_threads();

              for (int j = id; j < p; j+=count) {
                  double tempb[n];
                  for(int t = 0; t < n; t++){tempb[t] = b[t][j]; }
                  c[i][j] = dot(n, a[i], tempb);
			//printf("dot sent to thread %d\n", id);
			//printf("result: %f\n", c[i][j]);
              }
          }
	    #pragma omp barrier
      }
	return c;
}