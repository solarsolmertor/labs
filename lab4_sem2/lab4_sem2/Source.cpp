#include "./Header.h"

void fillArray(int* arr, int size) {
    cout << "Initial values of array: ";
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % 20 - 10;
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void findResult(int* arr, int size) {
    int sum = 0, amount = 0;
    int* arr1 = new int[amount + 1];
    for (int i = 0; i < size; i++) {
        if (abs(*(arr + i)) < 5) {
            *(arr1 + amount) = *(arr + i);
            amount++;
            sum += *(arr + i);
        }
    }
    cout << "Total amount of absolute values < 5: " << amount << endl;
    cout << "Sum of values: " << sum << endl;
    cout << "Values of new array: ";
    for (int i = 0; i < amount; i++) {
        cout << *(arr1 + i) << " ";
    }
}
