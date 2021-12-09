#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

struct transition {
    char substance[10];
    char type;
    float minTemperature;
    float maxTemperature;
} transitionArray[10];

int main(void) {
    struct transition result;
    int n;
    int i, j;
    int min;
    float sqx = 0.00, sqx1 = 0.00;

    for (n = 0; n < 10; n++) {
        printf("%d. Enter: Substance, type, temperature >", n + 1);
        scanf("%s", transitionArray[n].substance);
        if (!strcmp(transitionArray[n].substance, "***")) break;
        scanf("%s", &transitionArray[n].type);
        scanf("%f", &sqx); transitionArray[n].minTemperature = sqx;
        scanf("%f", &sqx1); transitionArray[n].maxTemperature = sqx1;
    }

    printf("------------------------------------------------------------------\n");
    printf("|Temperature of substances in a superconducting state            |\n");
    printf("|----------------------------------------------------------------|\n");
    printf("|Substance                  |Type       |Temperature             |\n");
    printf("|---------------------------|-----------|------------------------|\n");

    for (i = 0; i < n; i++) {
        printf(
            "|%-27s|%-11c|%-2.1f-%-20.1f|\n",
            transitionArray[i].substance,
            transitionArray[i].type,
            transitionArray[i].minTemperature,
            transitionArray[i].maxTemperature
        );
    }
    printf("|----------------------------------------------------------------|\n");

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(transitionArray[min].substance, transitionArray[j].substance) > 0) {
                min = j;
            }
        if (min > i) {
            strcpy(result.substance, transitionArray[i].substance);
            result.type = transitionArray[i].type;
            result.minTemperature = transitionArray[i].minTemperature;
            result.maxTemperature = transitionArray[i].maxTemperature;
            strcpy(transitionArray[i].substance, transitionArray[min].substance);
            transitionArray[i].type = transitionArray[min].type;
            transitionArray[i].minTemperature = transitionArray[min].minTemperature;
            transitionArray[i].maxTemperature = transitionArray[min].maxTemperature;
            strcpy(transitionArray[min].substance, result.substance);
            transitionArray[min].type = result.type;
            transitionArray[min].minTemperature = result.minTemperature;
            transitionArray[min].maxTemperature = result.maxTemperature;
        }
    }

    printf("------------------------------------------------------------------\n");
    printf("|Temperature of substances in a superconducting state            |\n");
    printf("|----------------------------------------------------------------|\n");
    printf("|Substance                  |Type       |Temperature             |\n");
    printf("|---------------------------|-----------|------------------------|\n");

    for (i = 0; i < n; i++) {
        printf(
            "|%-27s|%-11c|%-2.1f-%-20.1f|\n",
            transitionArray[i].substance,
            transitionArray[i].type,
            transitionArray[i].minTemperature,
            transitionArray[i].maxTemperature
        );
    }
    printf("|----------------------------------------------------------------|\n");
    return 0;
}
