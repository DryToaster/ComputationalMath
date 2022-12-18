#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "powershifted.c"

int main()
{
    // Initialization of matrices
    // a is mxn, x0 is n
    int m = 10;
    int n = 10;
    double a[10][10];
    printf("The generated random matrix is:\n");

    {

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100;
            printf("%.2f ", a[i][j]);
        }
    }
    }
    double x0[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double x1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double q0[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double tol = 0.0001;
    int maxIter = 100;

    double lambda;

    lambda = powershifted(n, 100.0, a, tol, maxIter);
    printf("\n\nThe largest eigenvalue is: %.5f", lambda);
}