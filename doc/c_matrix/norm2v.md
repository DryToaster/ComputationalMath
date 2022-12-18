# norm2v
**Function Name:** norm2v   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the 2-norm (magnitude) of a vector.  
**Input:** This function a vector `double v[]` and an `int n` representing the size of the vector.
**Output:** This function returns a `double` representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double norm;  
norm = norm2v(3, a);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double norm2v(int n, double v[n])
{
	static double c;
	c=0.0;
	for (int i=0; i < n; i++)
	{
		c += powf((v[i]),2.0);
	}
	return powf(c, 0.5);
}

```
**Last Modified:** 11/19/22