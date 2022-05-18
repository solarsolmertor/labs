#include "./Header.h"

//get length of list
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

//create new list
Node* createList(Node* head) {
    Node* newNode = new Node[sizeof(Node)];
    newNode->next = NULL;
    head = newNode;
    return head;
}

//print list
void printList(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->name << " " << temp->type << " " << temp->minTemp << " " << temp->maxTemp << endl;
        temp = temp->next;
    }
}

//search list by name and print
Node* searchList(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return head;
    }
    string name;
    cout << "¬ведите им€: ";
    cin >> name;
    Node* current = head;
    while (current != NULL) {
        if (current->name == name) {
            cout << current->name << " " << current->type << " " << current->minTemp << " " << current->maxTemp << endl;
            return current;
        }
        current = current->next;
    }
    cout << "Ёлемент не найден" << endl;
    return NULL;
}

//add node to list to any position
Node* addNode(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return head;
    }
    Node* newNode = new Node[sizeof(Node)];
    int position;
    cout << "¬ведите позицию: ";
    cin >> position;
    cout << "¬ведите им€: ";
    cin >> newNode->name;
    cout << "¬ведите тип: ";
    cin >> newNode->type;
    cout << "¬ведите минимальную температуру: ";
    cin >> newNode->minTemp;
    cout << "¬ведите максимальную температуру: ";
    cin >> newNode->maxTemp;
    newNode->next = NULL;
    Node* current = head;
    if (position < 0 || position > getLength(head)) {
        newNode->next = NULL;
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

//remove node from list by its pisition
Node* removeNode(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return head;
    }
    int position;
    cout << "¬ведите позицию: ";
    cin >> position;
    Node* current = head;
    if (position < 0 || position > getLength(head) - 1) {
        cout << "Ёлемент не найден" << endl;
        return head;
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    return head;
}

//sort list by name
Node* sortList(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return head;
    }
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        Node* next = current->next;
        while (next != NULL) {
            if (current->name > next->name) {
                string tempName = current->name;
                char tempType = current->type;
                float tempMinTemp = current->minTemp;
                float tempMaxTemp = current->maxTemp;
                current->name = next->name;
                current->type = next->type;
                current->minTemp = next->minTemp;
                current->maxTemp = next->maxTemp;
                next->name = tempName;
                next->type = tempType;
                next->minTemp = tempMinTemp;
                next->maxTemp = tempMaxTemp;
            }
            next = next->next;
        }
        current = current->next;
    }
    return head;
}

//write list to file
void writeList(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return;
    }
    ofstream file;
    file.open("test.txt");
    Node* current = head;
    while (current != NULL) {
        file << current->name << " " << current->type << " " << current->minTemp << " " << current->maxTemp << endl;
        current = current->next;
    }
    file.close();
}

//create new list from file
Node* createListFromFile(Node* head) {
    ifstream file;
    file.open("test.txt");
    string name;
    char type;
    float minTemp;
    float maxTemp;
    while (file >> name >> type >> minTemp >> maxTemp) {
        Node* newNode = new Node[sizeof(Node)];
        newNode->name = name;
        newNode->type = type;
        newNode->minTemp = minTemp;
        newNode->maxTemp = maxTemp;
        newNode->next = NULL;
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    file.close();
    return head;
}
