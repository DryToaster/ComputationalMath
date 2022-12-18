# trapezoidOMP
**Function Name:** trapezoidOMP   
**Author:** Nathan Nelson  
**Language:** C, with OpenMP library  
**Description/Purpose:** This function computes an estimate of a definite integral of a given function using the trapezoid method. It is implemented with cyclic parallel execution using OMP directives.  
**Input:** This function takes a function pointer `f` representing the function f to be integrated, `double`s `a` and `b` representing the interval of interest, and an `int n` representing the number of partitions to make in the estimate.  
**Output:** This function returns the digits of precision as an `int`. 
**Usage/Example:** The function to be integrated on must be defined seperately and passed in as a pointer; all other arguments can be passed in literally.:  
`double estimate = trapezoidOMP(f, 1.0, 2.0, 50);`  


**Implementation/Code:** This is the function implementation in C:  
```
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

```
**Last Modified:** 11/19/22