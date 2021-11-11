#define _CRT_SECURE_NO_WARNINGS
#include "math.h"
#include <iostream>

int main() {
    double x, y; // input values
    int radius = 1; // radius of semicircle
    while (true) {
        scanf("%lf %lf", &x, &y); // entering values
        printf("x = %6.3lf;  y = %6.3lf\n", x, y); // checking them
        if ((x >= -1 && x <= 1) && ((y >= -1 && y <= 0) || (y <= 1 && y >= 0 && (pow(x, 2) + pow(y, 2) <= radius)))) { // condition for point
            printf("This point is in the area\n"); // in graph
        }
        else {
            printf("This point isn't in the area\n"); // not in graph
        }
    }
    return 0;
}
