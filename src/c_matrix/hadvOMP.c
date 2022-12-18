#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 12
static double* hadvOMP(int n, double u[n], double v[n])
{
	double* w;
	w = malloc(sizeof(double*)*n);
	omp_set_num_threads(NUM_THREADS);

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int count = omp_get_num_threads();
		for(int i = id; i < n; i += count)
		{
			w[i] = u[i]*v[i];
		}	
	}
	#pragma omp barrier
	return w;
}