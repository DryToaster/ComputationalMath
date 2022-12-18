# scalev
**Function Name:** scalev   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns a vector scaled by a provided scalar. This function depends on "dotv" and "crossv". The function assumes each of the input vectors are of dimension 3.  
**Input:** This function requires a vector `double v[]`, a scalar `double a`, and an `int n` representing the size of the vector.  
**Output:** This function returns a pointer to a vector/array representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double prod;  
prod = tripv(a, b, c);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "crossv.c"
#include "dotv.c"

static double tripv(double a[3], double b[3], double c[3])
{
	double* dptr;
	dptr = crossv(b, c);
	double d[3];
	d[0] = dptr[0];
	d[1] = dptr[1];
	d[2] = dptr[2];
	return dotv(a, d, 3);
}

```
**Last Modified:** 11/19/22