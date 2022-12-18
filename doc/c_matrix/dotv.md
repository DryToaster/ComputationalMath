# dotv
**Function Name:** dotv   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the dot product of two vectors.  
**Input:** This function takes two vectors, `double a[]` and `double b[]`.
**Output:** This function returns a pointer to a vector/array representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double prod;  
prod = dotv(3, a, b);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double dotv(int n, double a[n], double b[n])
{
	static double c;
	c = 0;
	for (int i=0; i < n; i++)
	{
		c += a[i] * b[i];
	}
	return c;
}

```
**Last Modified:** 11/19/22