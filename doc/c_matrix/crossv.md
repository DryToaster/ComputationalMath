# crossv
**Function Name:** crossv   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the cross product of two vectors in three dimensions  
**Input:** This function takes two vectors, `double a[]` and `double b[]`.
**Output:** This function returns a pointer to a vector/array representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double* prod;  
prod = crossv(a, b);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double* crossv(double a[3], double b[3])
{
	static double * c;
	c = malloc(sizeof(double*));
	
	c[0] = b[3]*a[2] - a[3]*b[2];
	c[1] = b[1]*a[3] - a[1]*b[3];
	c[2] = b[2]*a[1] - a[2]*b[1];
	return c;
}

```
**Last Modified:** 11/19/22