# absErr
**Function Name:** abserr  
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function determines the absolute error of an approximation of a value.  
**Input:** This function takes a value `double u`, and an estimate `double v` of that value.  
**Output:** This function returns the absolute error as a `double`. 
**Usage/Example:** All inputs are taken as arguments; if we want to store the in `x`:  
`double x = abserr(5.0, 4.129357654);`  


**Implementation/Code:** This is the function implementation in C:  
```
#include <math.h>
#include <limits.h>

double abserr(double u, double v) {
	return fabs(u - v);
}


```
**Last Modified:** 10/19/22