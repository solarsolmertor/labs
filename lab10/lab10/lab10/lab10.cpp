#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctime>

int modify_array(int* arr, const int M, const int N) {
    int** modArray = (int**)malloc(M * sizeof(int*));
    for (size_t i = 0; i < M; i++)
        modArray[i] = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            modArray[i][j] = arr[i * N + j];
        }
    }
    printf("\n2D array looks like:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", modArray[i][j]);
        }
        printf("\n");
    }
    int* maxArray = (int*)malloc(M * sizeof(int));
    int max = modArray[0][0];
    for (int i = 0; i < M; i++) {
        max = modArray[i][0];
        for (int j = 0; j < N; j++) {
            if (max < modArray[i][j]) {
                max = modArray[i][j];
            }
        }
        maxArray[i] = max;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            modArray[i][j] *= maxArray[i];
        }
    }
    printf("\nModified 2D array looks like:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", modArray[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arr[i * N + j] = modArray[i][j];
        }
    }
    int multiplyResult = 1;
    for (int i = 0; i < M; i++) {
        multiplyResult *= maxArray[i];
    }
    return multiplyResult;
}

int main() {
    int M, N;
    printf("Enter numbers of row and column of one-dimensional array (M * N): ");
    scanf("%d %d", &M, &N);
    int* arr = (int*)malloc((M * N) * sizeof(int));
    srand(time(0));
    for (size_t i = 0; i < M * N; i++) {
        arr[i] = rand() % 200 - 100;
    }
    printf("\n1D array looks like:\n");
    for (int i = 0; i < M * N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    modify_array(arr, M, N);
    printf("\nModified 1D array looks like:\n");
    for (int i = 0; i < M * N; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
