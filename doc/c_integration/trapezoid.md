# trapezoid
**Function Name:** trapezoid   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function computes an estimate of a definite integral of a given function using the trapezoid method.  
**Input:** This function takes a function pointer `f` representing the function f to be integrated, `double`s `a` and `b` representing the interval of interest, and an `int n` representing the number of partitions to make in the estimate.  
**Output:** This function returns the digits of precision as an `int`. 
**Usage/Example:** The function to be integrated on must be defined seperately and passed in as a pointer; all other arguments can be passed in literally.:  
`double estimate = trapezoid(f, 1.0, 2.0, 50);`  


**Implementation/Code:** This is the function implementation in C:  
```
#include <math.h>
static double trapezoid(double (*f)(), double a, double b, int n)
{
	double h = (b - a) / (float)n;
	
	int iters = 1;

	double sum = (f(a)+f(b))/2.0;
	
	double x_1 = a + h;

	for (int i = 0; i < n; i++)
	{
		sum += f(x_1 + (i)*h);
	}

	
	return sum*h;
}

```
**Last Modified:** 11/19/22