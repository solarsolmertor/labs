#include "./Header.h"

void arrayFillingByHands(Chemistry arr[]) {
#ifdef DEBUG
    cout << "Дата:" << __DATE__ << "; Время:" << __TIME__ << endl;
#endif
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << "Enter name of substance: ";
        cin >> arr[i].name;
        cout << "Enter type: ";
        cin >> arr[i].type;
        cout << "Enter temperature: ";
        cin >> arr[i].temperature;
    }
#ifdef DEBUG
    cout << "Имя текущего файла:" << __FILE__ << "; Имя текущей функции:" << __FUNCTION__ << endl;
#endif
}

void arrayFillingAuto(Chemistry arr[]) {
#ifdef DEBUG
    cout << "Дата:" << __DATE__ << "; Время:" << __TIME__ << endl;
#endif
    Chemistry arr1[SIZE] = {
        "Zn", 'M', "0.8-0.8",
        "Pb-Au", 'A', "2.0-7.3",
        "NbC", 'C', "10.1-10.5"
    };

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = arr1[i];
    }
#ifdef DEBUG
    cout << "Имя текущего файла:" << __FILE__ << "; Имя текущей функции:" << __FUNCTION__ << endl;
#endif
}

void outPut(Chemistry arr[]) {
#ifdef DEBUG
    cout << "Дата:" << __DATE__ << "; Время:" << __TIME__ << endl;
#endif
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
#ifdef DEBUG
    cout << "Имя текущего файла:" << __FILE__ << "; Имя текущей функции:" << __FUNCTION__ << endl;
#endif
}

void sort(Chemistry arr[]) {
#ifdef DEBUG
    cout << "Дата:" << __DATE__ << "; Время:" << __TIME__ << endl;
#endif
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i; j < SIZE; j++) {
            if (arr[i].name < arr[j].name)
                swap(arr[i], arr[j]);
        }
    }
#ifdef DEBUG
    cout << "Имя текущего файла:" << __FILE__ << "; Имя текущей функции:" << __FUNCTION__ << endl;
#endif
}