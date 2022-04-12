#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 3;
bool isEmpty = true;

struct Chemistry {
    char name[20];
    char type;
    char temperature[20];
};

void arrayFillingByHands(Chemistry arr[]) {
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << "Enter name of substance: ";
        cin >> arr[i].name;
        cout << "Enter type: ";
        cin >> arr[i].type;
        cout << "Enter temperature: ";
        cin >> arr[i].temperature;
    }
}

void arrayFillingAuto(Chemistry arr[]) {
    Chemistry arr1[SIZE] = {
        "Zn", 'M', "0.8-0.8",
        "Pb-Au", 'A', "2.0-7.3",
        "NbC", 'C', "10.1-10.5"
    };

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = arr1[i];
    }
}

void outPut(Chemistry arr[]) {
    cout << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|Temperature of substances in a superconducting state            |" << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|Substance                  |Type       |Temperature             |" << endl;
    cout << "|---------------------------|-----------|------------------------|" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        printf("|%-27s|%-11c|%-24s|\n", arr[i].name, arr[i].type, arr[i].temperature);
    }
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|Type of substance: M - metal, A - alloy, C - compound           |" << endl;
    cout << "|----------------------------------------------------------------|" << endl;

}

void sort(Chemistry arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i; j < SIZE; j++) {
            if (arr[i].name < arr[j].name)
                swap(arr[i], arr[j]);
        }
    }
}

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