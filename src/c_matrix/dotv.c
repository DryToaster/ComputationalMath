#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double dotv(int n, double a[n], double b[n])
{
	static double c;
	c = 0;
	for (int i=0; i < n; i++)
	{
		c += a[i] * b[i];
	}
	return c;
}
