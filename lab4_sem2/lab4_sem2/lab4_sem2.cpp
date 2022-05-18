#include "./Header.h"

int main() {
    srand(time(NULL));
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int* arr = new int[size];
    fillArray(arr, size);
    findResult(arr, size);
    return 0;
}