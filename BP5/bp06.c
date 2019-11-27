#include <stdio.h>
#include <float.h>
#include <math.h>
#include <errno.h>
#include <limits.h>

#include "input.h"
#include "my_math.h"

void my_pow_tests(void);

int main(void)
{
	double d1;
	
	my_pow_tests();
	
	printf("Eingabe des ersten Parameters fuer alle Funktionen\n");
	printf("(Programmabbruch durch Falscheingabe): ");

	d1 = read_double();

	while (d1 != DBL_MIN && d1 != DBL_MAX) {
		double d2;
		printf("my_fabs(%f) = %f\n", d1, my_fabs(d1));
		printf("\nEingabe des zweiten Parameters fuer my_pow\n");
		printf("(Berechnungsabbruch durch Falscheingabe): ");
		d2 = read_double();
		while (d2 != DBL_MIN && d2 != DBL_MAX) {
			int i = d2;
			printf("my_pow(%f, %i) = %e\n", d1, i, my_pow(d1, i));
			printf("errno: %i\n", errno);
			printf("\nEingabe des zweiten Parameters fuer my_pow\n");
			printf("(Berechnungsabbruch durch Falscheingabe): ");
			d2 = read_double();
		}
		printf("\nEingabe des ersten Parameters fuer alle Funktionen\n");
		printf("(Programmabbruch durch Falscheingabe): ");
		d1 = read_double();
	}
	return 0;
}

void my_pow_tests(void)
{
	printf("MY_POW TESTS (SUCCESS == 1 / FAILURE == 0)\n");
	printf("=================================================\n");
	printf("my_pow(2, 5): \t\t\t%i\t", my_pow(2, 5) == pow(2, 5));
	my_pow(2, 5);
	printf("errno: %i\n", errno);
	printf("my_pow(-2, -4): \t\t%i\t", my_pow(-2, -4) == pow(-2, -4));
	my_pow(-2, -4);
	printf("errno: %i\n", errno);
	printf("my_pow(1, 15): \t\t\t%i\t", my_pow(1, 15) == pow(1, 15));
	my_pow(1, 15);
	printf("errno: %i\n", errno);
	printf("my_pow(-4, 414): \t\t%i\t", my_pow(-4, 414) == pow(-4, 414));
	my_pow(-4, 414);
	printf("errno: %i\n", errno);
	printf("my_pow(-5, 303): \t\t%i\t", my_pow(-5, 303) == pow(-5, 303));
	my_pow(-5, 303);
	printf("errno: %i\n", errno);
	printf("my_pow(0, -3): \t\t\t%i\t", my_pow(0, -3) == 0);
	my_pow(0, -3);
	printf("errno: %i\n", errno);
	printf("my_pow(1.0e-10, 100): \t\t%i\t", my_pow(1.0e-10, 100) == pow(1.0e-10, 100));
	my_pow(1.0e-10, 100);
	printf("errno: %i\n", errno);
	printf("my_pow(-1.0e-10, 101): \t\t%i\t", my_pow(-1.0e-10, 101) == pow(-1.0e-10, 101));
	my_pow(-1.0e-10, 101);
	printf("errno: %i\n", errno);
	printf("my_pow(-111, INT_MAX): \t\t%i\t", my_pow(-111, INT_MAX) == pow(-111, INT_MAX));
	my_pow(-111, INT_MAX);
	printf("errno: %i\n", errno);
	printf("my_pow(-111, INT_MAX-1): \t%i\t", my_pow(-111, INT_MAX-1) == pow(-111, INT_MAX-1));
	my_pow(-111, INT_MAX-1);
	printf("errno: %i\n", errno);
	printf("my_pow(-111, -INT_MAX): \t%i\t", my_pow(-111, -INT_MAX) == pow(-111, -INT_MAX));
	my_pow(-111, -INT_MAX);
	printf("errno: %i\n", errno);
	printf("my_pow(-111, -INT_MAX+1): \t%i\t", my_pow(-111, -INT_MAX+1) == pow(-111, -INT_MAX+1));
	my_pow(-111, -INT_MAX+1);
	printf("errno: %i\n", errno);
	printf("=================================================\n");
	printf("errno (EDOM: %i / ERANGE: %i)\n\n", EDOM, ERANGE);
}
