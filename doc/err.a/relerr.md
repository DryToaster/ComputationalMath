# relErr
**Function Name:** relerr  
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function determines the relative error of an approximation of a value.  
**Input:** This function takes a value `double u`, and an estimate `double v` of that value.  
**Output:** This function returns the relative error as a `double`. If the estimate `u` is zero, `LLONG_MAX` is returned instead.
**Usage/Example:** All inputs are taken as arguments; if we want to store the in `x`:  
`double x = relerr(5.0, 4.129357654);`  


**Implementation/Code:** This is the function implementation in C:  
```
#include <math.h>
#include <limits.h>

double relerr(double u, double v) {
	if (u == 0) {
		return LLONG_MAX;
	}
	return (fabs(u - v) / u);
}


```
**Last Modified:** 10/19/22