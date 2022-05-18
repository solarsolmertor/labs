#include "./Header.h"

int main() {
    setlocale(LC_ALL, "ru");
    Node* head = NULL;
    int x;
    while (true) {
        cout << " 1. Создать двусвязный список" << endl;
        cout << " 2. Вывести двусвязный список с начала" << endl;
        cout << " 3. Вывести двусвязный список с конца" << endl;
        cout << " 4. Найти элемент в двусвязном списке с начала" << endl;
        cout << " 5. Найти элемент в двусвязном списке с конца" << endl;
        cout << " 6. Добавить элемент в двусвязный список" << endl;
        cout << " 7. Удалить элемент из двусвязного списка" << endl;
        cout << " 8. Сортировать двусвязный список" << endl;
        cout << " 9. Записать двусвязный список в файл" << endl;
        cout << " 10. Считать двусвязный список из файла" << endl;
        cout << " 11. Выход" << endl;
        cin >> x;
        switch (x) {
        case 1:
            head = createList(head);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printListFromTail(head);
            break;
        case 4:
            searchList(head);
            break;
        case 5:
            searchListFromTail(head);
            break;
        case 6:
            addNode(head);
            break;
        case 7:
            deleteNode(head);
            break;
        case 8:
            sortList(head);
            break;
        case 9:
            writeList(head);
            break;
        case 10:
            head = createList(head);
            readList(head);
            break;
        case 11:
            exit(0);
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
}
