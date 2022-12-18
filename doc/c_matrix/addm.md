# addm
**Function Name:** addm   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the sum of two matrices of the same size.  
**Input:** this function takes two matrices, `double a[]` and `double b[]`, as well as the dimensions `int m` and `int n` of the matrices.
**Output:** This function returns a pointer to a matrix representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double** sum;  
sum = addm(3, 3, a, b);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double **addm(int m, int n, double a[m][n], double b[m][n]){
    double **c;
    c = malloc(sizeof(double*)*m);
    printf("    \n");

    for(int i = 0; i < m; i++) {
        c[i] = malloc(sizeof(double*)*n);
    }

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        	c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}


```
**Last Modified:** 11/19/22