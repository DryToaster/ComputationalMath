# norminfv
**Function Name:** norminfv   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the inf-norm of a vector.  
**Input:** This function takes a vector `double v[]` and an `int n` representing the size of the vector.
**Output:** This function returns a `double` representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double norm;  
norm = norminfv(3, v);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
static double norminfv(int n, double v[n])
{
	static double c;
	c=0.0;
	for (int i=0; i < n; i++)
	{
		c = fmax(fabs(v[i]), c);
	}
	return c;
}

```
**Last Modified:** 11/19/22