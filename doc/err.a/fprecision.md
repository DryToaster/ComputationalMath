# fPrecision
**Function Name:** fprecision   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function determines the number of digits of precision of an estimate.  
**Input:** This function takes a value `float u`, and an estimate `float v` of that value.  
**Output:** This function returns the digits of precision as an `int`. 
**Usage/Example:** All inputs are taken as arguments; if we want to store the digits of precision in `x`:  
`int x = fprecision(5.0, 4.9999999935);`  


**Implementation/Code:** This is the function implementation in C:  
```
#include <math.h>
#include <limits.h>

int fprecision(float u, float v) {
	float diff = fabs(u - v);
	float dpower = log10f(diff);
	float upower = log10f(u);
	return (floor(upower - dpower));
}

```
**Last Modified:** 10/19/22