# norm1v
**Function Name:** norm1v   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the 1-norm of a vector.  
**Input:** This function takes a vector `double[] v` and an `int n` representing its size..
**Output:** This function returns the result of the operation as a double. 
**Usage/Example:** All paramaters are passed in literally:  
```
double norm;  
norm = normv(3, a);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double norm1v(int n, double v[n])
{
	static double c;
	c=0.0;

	for (int i=0; i < n; i++)
	{
		c += fabs(v[i]);
	}
	return c;
}

```
**Last Modified:** 11/19/22