#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "math.h"

int main() {
    long n;
    double sum = 0, term, dbln;
    const double eps = 0.000001;
    short k1 = 1; // pow(-1, n)

    for (n = 0; ; n++, k1 = -k1) {
        dbln = n;
        term = k1 * (2 * dbln + 1) / (pow(dbln, 3) + 1);
        if (fabs(term) >= eps) {
            sum += term;
        }
        else break;
        if (n == 9) {
            printf("Sum of 10 numbers of range = %10.7lf\n", sum);
        }
    }
    printf("Full sum of range = %10.7lf\n", sum);
    return 0;
}
