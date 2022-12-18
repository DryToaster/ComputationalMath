#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "power.c"

int main()
{

    int m = 10;
    int n = 10;
    double a[10][10];
    printf("The generated random matrix is:\n");

    

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100;
            printf("%.2f ", a[i][j]);
        }
    }
    
    

    double lmax;
    double lmin;
    double lat01;
    double lat03;
    double lat10;
    double lat20;
    double lat100;

    lmax = power1(n, a, .0001, 200);
    lmin = inversepower(n, a, .0001, 200);
    lat01 = powershifted(n, 0.1, a, .0001, 200);
    lat03 = powershifted(n, 0.3, a, .0001, 200);
    lat10 = powershifted(n, 1.0, a, .0001, 200);
    lat20 = powershifted(n, 2.0, a, .0001, 200);
    //lat100 = powershifted(n, 100.0, a, .0001, 200);

    printf("\n\nThe largest eigenvalue is: %.5f", lmax);
    printf("\n\nThe smallest eigenvalue is: %.5f", lmin);
    printf("\n\nThe 0.1est eigenvalue is: %.5f", lat01);
    printf("\n\nThe 0.3est eigenvalue is: %.5f", lat03);
    printf("\n\nThe 1.0est eigenvalue is: %.5f", lat10);
    printf("\n\nThe 2.0est eigenvalue is: %.5f", lat20);
    //printf("\n\nThe 100.0est eigenvalue is: %.5f", lat100);
    


}




