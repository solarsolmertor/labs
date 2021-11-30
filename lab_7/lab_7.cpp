#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "math.h"

int main() {
    short n;
    double x, y;
    double h;
    double thirdPart = 0.33;

    for (n = 0; n < 5; n++) {
        printf("|   x   |      y     |\n");
        printf("|-------|------------|\n");
        for (x = 0; x <= 4; x += 0.25) {

            /* 1-й отрезок */
            if (x < 1) {
                y = -x;
                printf("| %5.2lf | %10.7lf |", x + n * 4, y);
                h = (y + 1) * 30;
                if (y - 1 - h * 10 > 0.5) h++;
                for (; h > 0; h--) printf(" ");
                printf("*\n");
            }

            /* 2-й отрезок */
            else if (x == 1) {
                y = -1;
                printf("| %5.2lf | %10.7lf |", x + n * 4, y);
                h = (y + 1) * 30;
                if (y - 1 - h * 10 > 0.5) h++;
                for (; h > 0; h--) printf(" ");
                printf("*");
                while (y < 0) {
                    y += 0.25;
                    h = (y + 1) * 10;
                    if (y - 1 - h * 10 > 0.5) h++;
                    for (; h > 0; h--) printf(" ");
                    printf("*");
                }
                printf("\n");
            }

            /* 3-й отрезок */
            else if (x < 4) {
                y = thirdPart - thirdPart * x;
                printf("| %5.2lf | %10.7lf |", x + n * 4, y);
                h = (y + 1) * 30;
                if (y - 1 - h * 10 > 0.5) h++;
                for (; h > 0; h--) printf(" ");
                printf("*\n");
            }

            /* 4-й отрезок */
            else if (x == 4) {
                y = -1;
                printf("| %5.2lf | %10.7lf |", x + n * 4, y);
                h = (y + 1) * 30;
                if (y - 1 - h * 10 > 0.5) h++;
                for (; h > 0; h--) printf(" ");
                printf("*");
                while (y < 0) {
                    y += 0.25;
                    h = (y + 1) * 10;
                    if (y - 1 - h * 10 > 0.5) h++;
                    for (; h > 0; h--) printf(" ");
                    printf("*");
                }
                printf("\n");
            }
        }  /* конец внутреннего цикла */
        printf("Press Enter...");
        getchar();
    }
    return 0;
}
