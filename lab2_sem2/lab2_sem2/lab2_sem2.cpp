#include "./Header.h"

bool isEmpty = true;

int main() {
    setlocale(LC_ALL, "Russian");
    Chemistry arr[SIZE];

    while (true)
    {
        int c;
        cout << "Enter 1 to fill structure" << endl;
        cout << "Enter 2 to fill structure automatically" << endl;
        cout << "Enter 3 to output structure" << endl;
        cout << "Enter 4 to sort structure" << endl;
        cout << "Enter 0 to exit" << endl << endl;
        cin >> c;
        cout << endl;
        switch (c)
        {

        case 1:
            arrayFillingByHands(arr);
            isEmpty = false;
            cout << "Structure filled" << endl;
            break;
        case 2:
            arrayFillingAuto(arr);
            isEmpty = false;
            cout << "Structure filled" << endl;
            break;
        case 3:
            if (isEmpty) {
                cout << "No data in structure! Please fill" << endl;
                break;
            }
            outPut(arr);
            break;
        case 4:
            if (isEmpty) {
                cout << "No data in structure! Please fill" << endl;
                break;
            }
            sort(arr);
            cout << "Sorted" << endl;
            break;
        case 0:
            break;
        default:
            cout << "False statement, try again" << endl;
        }
        system("pause");
        system("cls");
        if (c == 0) break;
    }
    return 0;
}