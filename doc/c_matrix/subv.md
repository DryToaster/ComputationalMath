# subv
**Function Name:** subv   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the difference of two vectors  
**Input:** This function takes two vectors, `double a[]` and `double b[]`, as well as an `int n` to represent the size of the vectors.
**Output:** This function returns a pointer to a vector/array representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double* diff;  
diff = subv(3, a, b);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* subv(double a[], double b[], int size)
{
	static double * c;
	c = malloc(sizeof(double*)*size);
	for (int i=0; i < size; i++)
	{
		c[i] = a[i] - b[i];
	}
	return c;
}


```
**Last Modified:** 11/19/22