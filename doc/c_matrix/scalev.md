# scalev
**Function Name:** scalev   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns a vector scaled by a provided scalar.  
**Input:** This function requires a vector `double v[]`, a scalar `double a`, and an `int n` representing the size of the vector.  
**Output:** This function returns a pointer to a vector/array representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double* vec;  
vec = scalev(3, a, 10.0);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* scalev(size n, double a, double b[n])
{
	static double * c;
	c = malloc(sizeof(double*)*n);
	for (int i=0; i < n; i++)
	{
		c[i] = a * b[i];
	}
	return c;
}

```
**Last Modified:** 11/19/22