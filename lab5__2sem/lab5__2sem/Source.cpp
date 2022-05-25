#include "./Header.h"

void SingleArrayTransformation(int* array, int cols, int rows) {
    int i, j, k = 1;
    for (i = 0; i < rows; i++)
        for (j = 0; j <= i; j++)
            *(array + j * rows + i - j) = k++;

    for (i = 1; i < rows; i++)
        for (j = i; j < cols; j++)
            *(array + j * rows + rows - j + i - 1) = k++;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cout << *(array + i * rows + j) << " ";
        }
        cout << endl;
    }
}

void DoubleArrayTransformation(int** arr, int cols, int rows) {
    int i, j, k = 1;
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    for (i = 0; i < rows; i++)
        for (j = 0; j <= i; j++)
            arr[j][i - j] = k++;

    for (i = 1; i < rows; i++)
        for (j = i; j < cols; j++)
            arr[j][rows - j + i - 1] = k++;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Menu(int** arr, int* array, int cols, int rows) {
    int c;
#ifdef  TEST_MODE
    while (true) {
        cout << "Enter 1 to transform single array: " << endl;
        cout << "Enter 2 to transform double array: " << endl;
        cout << "Enter 0 to exit: " << endl;
        cin >> c;
        switch (c) {
        case 1:
            SingleArrayTransformation(array, cols, rows);
            cout << "\nArray filled" << endl;
            break;
        case 2:
            DoubleArrayTransformation(arr, cols, rows);
            cout << "\nArray filled" << endl;
            break;
        case 0:
            break;
        default:
            cout << "False statment, try again" << endl;
        }
        if (c == 0) break;
    }
#endif //  TEST_MODE
}
