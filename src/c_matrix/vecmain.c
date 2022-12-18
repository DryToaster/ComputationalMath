#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "addv.c"
#include "subv.c"
#include "scalev.c"
#include "normv.c"
#include "tripv.c"
#include "addm.c"
#include "subm.c"
#include "prodm.c"
#include "prodmOMP.c"


int main()
{
	double vec1[3] = {2.0, 3.0, 4.0};
	double vec2[3] = {1.0, 3.0, 5.0};
	double vec3[3] = {5.0, 5.0, 5.0};

	double mtx1[3][3] = {{2.0,2.0,2.0}, {2.0,2.0,2.0}, {2.0,2.0,2.0}};
	double mtx2[3][3] = {{3.0,3.0,3.0}, {5.0,5.0,5.0}, {3.0,3.0,3.0}};

	printf("  owebu  \n");

	double *resadd;
	double *ressub;
	double *resscale;
	double resnorm1;
	double resnorm2;
	double resnorminf;
	double resdot;
	double *rescross;
	double restriple;
	double *resAv;
	double **ressum;
	double **resdiff;
	double **resAB;
      double **resABOMP;

	



	resdiff = prodmOMP(3, 3, 3, mtx1, mtx2);
	printf("baefo\n");
	
	for (int i=0; i < 3; i++)
            {
			
                for(int j=0; j < 3; j++)
                {
			
                    printf("%.2f    ", resdiff[i][j]);
                }
                printf("\n");
            }

	

	return 0;
}