#define  _CRT_SECURE_NO_WARNINGS
#include "math.h"
#include <iostream>

int main(void) {
	double x, y; // input values
	/* initial values */
	double a = 2.5, b = 1.4;
	double n = 2, m = 4;
	double t1, t2; // results
	double ax; // a * x

	printf("Enter x, y > ");
	scanf("%lf %lf", &x, &y); // enter x and y
	t1 = ((2 * sqrt(x)) / (3 * pow(b, 2)) - ((2 * pow(a, 2) * sqrt(x)) / pow(b, 4)) + ((2 * pow(a, 3) / pow(b, 5)) * y)); // calculating first formule
	ax = a * x * 3.14 / 180; // changing from degrees to radians
	t2 = (pow(sin(ax), n - 1) + pow(cos(ax), m - 1)) / (a * (n + m)); // calculating second formule
	/* output results */
	printf("t1 = %lg\n", t1);
	printf("t2 = %lg\n", t2);
	return 0;
}
