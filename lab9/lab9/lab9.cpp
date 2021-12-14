#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main() {
    const int N = 9;
    int mas[N][N];
    int i, j, k = 1;

    for (i = 0; i < N; i++)
        for (j = 0; j <= i; j++)
            mas[j][i - j] = k++;

    for (i = 1; i < N; i++)
        for (j = i; j < N; j++)
            mas[j][N - j + i - 1] = k++;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
    return 0;
}
