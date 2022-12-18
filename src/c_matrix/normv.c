#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double norm1v(int n, double v[n])
{
	static double c;
	c=0.0;

	for (int i=0; i < n; i++)
	{
		c += fabs(v[i]);
	}
	return c;
}

static double norm2v(int n, double v[n])
{
	static double c;
	c=0.0;
	for (int i=0; i < n; i++)
	{
		c += powf((v[i]),2.0);
	}
	return powf(c, 0.5);
}

static double norminfv(int n, double v[n])
{
	static double c;
	c=0.0;
	for (int i=0; i < n; i++)
	{
		c = fmax(fabs(v[i]), c);
	}
	return c;
}