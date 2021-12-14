#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

void fillArray(int** arr, const int N, const int M) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = rand() % 200 - 100;
        }
    }
}

void printArray(int** arr, const int N, const int M) {
    printf("\nGenerated array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int findPositiveElements(int** arr, const int N, const int M) {
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (arr[N - 1][i] > 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int numOfRows = 0, numOfColumns = 0;
    printf("Input number of rows: ");
    scanf("%d", &numOfRows);
    printf("Input number of columns: ");
    scanf("%d", &numOfColumns);

    // making dynamic memory for array
    int** arr = (int**)malloc(numOfRows * sizeof(int*));
    for (int i = 0; i < numOfRows; i++) {
        arr[i] = (int*)malloc(numOfColumns * sizeof(int));
    }

    // functions for filling, printing and finding positive elements of array
    fillArray(arr, numOfRows, numOfColumns);
    printArray(arr, numOfRows, numOfColumns);
    for (int i = 1; i <= numOfRows; i++) {
        printf("%d elements in %d row\n", findPositiveElements(arr, i, numOfColumns), i);
    }
    free(arr);
    return 0;
}
