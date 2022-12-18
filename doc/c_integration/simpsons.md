# simpsons
**Function Name:** simpsons   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function computes an estimate of a definite integral of a given function using Simpson's method.  
**Input:** This function takes a function pointer `f` representing the function fo be integrated, `double`s `a` and `b` representing the interval of interest, and an `int n` representing the number of partitions to make in the estimate.  
**Output:** This function returns the digits of precision as an `int`. 
**Usage/Example:** The function to be integrated on must be defined seperately and passed in as a pointer; all other arguments can be passed in literally.:  
`double estimate = simpsons(f, 1.0, 2.0, 50);`  


**Implementation/Code:** This is the function implementation in C:  
```
#include <math.h>
static double simpsons(double (*f)(), double a, double b, int n)
{
	int i = 2*n + 1;
	double h = (b-a)/(float)i;
	
	double sum = (f(a)+f(b)+4.0*f(b-h))/3.0;
	int iters = 0;	
	double halfsum = 0.0;
	double qrtrsum = 0.0;
	double x = a + h;
	while (iters < (n-1)/2)
	{
		qrtrsum += f(x);
		halfsum += f(h+h);
		
		x += 2.0*h;
		iters++;
	}
	return sum*h;
	
}

```
**Last Modified:** 11/19/22