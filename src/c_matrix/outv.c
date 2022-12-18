#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double **outv(int m, int n, double u[m], double v[n]){
    double **c;
    c = malloc(sizeof(double*)*m);
    printf("    \n");

    for(int i = 0; i < m; i++) {
        c[i] = malloc(sizeof(double*)*n);
    }

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i] * b[j];
        }
    }
    return c;
}
