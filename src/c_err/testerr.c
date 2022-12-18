#include "err.c"
#include <stdio.h>

int main() {
	double a = 5.0;
	double b = 4.999999;
	float c = 5.0;
	float d = 4.999;

	printf("Abserr: %.10f\n", abserr(a, b));
	printf("Relerr: %.10f\n", relerr(a, b));
	printf("Dprecision: %d\n", dprecision(a, b));
	printf("Fprecicion: %d\n", fprecision(c, d));



	return 0;
}