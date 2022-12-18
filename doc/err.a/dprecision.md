# dPrecision
**Function Name:** dprecision   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function determines the number of digits of precision of an estimate.  
**Input:** This function takes a value `double u`, and an estimate `double v` of that value.  
**Output:** This function returns the digits of precision as an `int`. 
**Usage/Example:** All inputs are taken as arguments; if we want to store the digits of precision in `x`:  
`int x = dprecision(5.0, 4.9999999935);`  


**Implementation/Code:** This is the function implementation in C:  
```
#include <math.h>
#include <limits.h>

int dprecision(double u, double v) {
	double diff = fabs(u - v);
	double dpower = log10l(diff);
	double upower = log10l(u);
	return (floor(upower - dpower));
}

```
**Last Modified:** 10/19/22