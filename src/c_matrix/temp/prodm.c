#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double **prodm(int m, int n, int p, double a[m][n], double b[n][p]){ 
    double **c;
    c = malloc(sizeof(double*)*m);
    printf("    \n");

    for (int i = 0; i < m; i++) {
        c[i] = malloc(sizeof(double*)*p);
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

