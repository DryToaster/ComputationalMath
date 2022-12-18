#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 12
static double trapezoidOMP(double (*f)(), double a, double b, int n)
{
	omp_set_num_threads(NUM_THREADS);
	
	double h = (b - a) / (float)n;
	
	double sum = (f(a)+f(b))/2.0;
	
	double x_1 = a + h;
	printf("here");
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int count = omp_get_num_threads();
		
		for (int i = id; i < n; i+=count)
		{
			#pragma omp critical
			{sum += f(x_1 + (i)*h);}
			
		}
	}
	#pragma omp barrier
	
	return sum*h;
}