#include "./Header.h"

int main() {
    setlocale(LC_ALL, "ru");
    Node* head = NULL;
    int x;
    while (true) {
        cout << " 1. Создать список" << endl;
        cout << " 2. Вывести список" << endl;
        cout << " 3. Найти элемент" << endl;
        cout << " 4. Добавить элемент" << endl;
        cout << " 5. Удалить элемент" << endl;
        cout << " 6. Сортировать список" << endl;
        cout << " 7. Записать список в файл" << endl;
        cout << " 8. Считать список из файла" << endl;
        cout << " 9. Выход" << endl;
        cin >> x;
        switch (x) {
        case 1:
            head = createList(head);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            searchList(head);
            break;
        case 4:
            addNode(head);
            break;
        case 5:
            removeNode(head);
            break;
        case 6:
            sortList(head);
            break;
        case 7:
            writeList(head);
            break;
        case 8:
            head = createList(head);
            createListFromFile(head);
            break;
        case 9:
            exit(0);
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
}