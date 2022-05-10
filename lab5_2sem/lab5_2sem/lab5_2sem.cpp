#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter size of matrix: ";
    cin >> size;
    int** mas = new int* [size];
    for (int i = 0; i < size; i++)
        mas[i] = new int[size];
    int i, j, k = 1;

    for (i = 0; i < size; i++)
        for (j = 0; j <= i; j++)
            mas[j][i - j] = k++;

    for (i = 1; i < size; i++)
        for (j = i; j < size; j++)
            mas[j][size - j + i - 1] = k++;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}