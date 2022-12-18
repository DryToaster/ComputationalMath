#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "crossv.c"
#include "dotv.c"

static double tripv(double a[3], double b[3], double c[3])
{
	double* dptr;
	dptr = crossv(b, c);
	double d[3];
	d[0] = dptr[0];
	d[1] = dptr[1];
	d[2] = dptr[2];
	return dotv(3, a, d);
}
