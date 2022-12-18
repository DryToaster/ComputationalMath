# prodm
**Function Name:** prodm   
**Author:** Nathan Nelson  
**Language:** C  
**Description/Purpose:** This function returns the prod of two matrices of the same size.  
**Input:** this function takes two matrices, `double a[]` and `double b[]`, as well as the dimensions `int m` and `int n` and `int p` of the matrices ("a" is m by n, "b" is n by p).  
**Output:** This function returns a pointer to a matrix representing the result of the operation. 
**Usage/Example:** All paramaters are passed in literally:  
```
double** prod;  
prod = prodm(3, 3, 3, a, b);  
```

**Implementation/Code:** This is the function implementation in C:  
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double **prodm(int m, int n, int p, double a[m][n], double b[n][p]){ 
    double **c;
    c = malloc(sizeof(double*)*m);
    printf("    \n");

    for (int i = 0; i < 3; i++) {
        c[i] = malloc(sizeof(double*)*p);
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            
            for (int k = 0; k < p; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

```
**Last Modified:** 11/19/22