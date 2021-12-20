#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ratio>
#include <thread>

void Merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};

void MergeSort(int* A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
    }
}

void pancakeSort(int* arr, int n) {
    for (int cur_size = n; cur_size > 1; cur_size--) {
        int ind_max = 0, temp;
        for (int ind = 0; ind < cur_size; ind++) {
            if (arr[ind] > arr[ind_max])
                ind_max = ind;
        }
        if (ind_max == cur_size - 1)
            continue;
        for (int j = 0, i = ind_max; j < i; i--, j++) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        for (int i = 0, j = cur_size - 1; i < j; i++, j--) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    int i, n;
    int* A = new int[100];
    int* B = new int[100];
    printf("\nSize of array > ");
    scanf("%d", &n);
    printf("\nMerge sort:\n");
    for (i = 1; i <= n; i++) {
        printf("%d element > ", i);
        scanf("%d", &A[i]);
    }
    auto begin = std::chrono::high_resolution_clock::now();
    MergeSort(A, 1, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> fsort_ms = end - begin;
    std::cout << "\nThe time: " << fsort_ms.count() << " ms\n";
    printf("\nOrdered by merge sort array:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", A[i]);
    free(A);
    printf("\n");
    int numOfElement;
    printf("\nPancake sort:\n");
    for (i = 0; i < n; i++) {
        numOfElement = i;
        printf("%d element > ", ++numOfElement);
        scanf("%d", &B[i]);
    }
    auto begin2 = std::chrono::high_resolution_clock::now();
    pancakeSort(B, n);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ssort_ms = end2 - begin2;
    std::cout << "\nThe time: " << ssort_ms.count() << " ms\n";
    printf("\nOrdered by pancake sort array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", B[i]);
    free(B);
    return 0;
}
