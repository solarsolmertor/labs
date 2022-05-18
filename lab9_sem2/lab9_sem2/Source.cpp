#include "./Header.h"

//get length of double linked list
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

//create double linked list
Node* createList(Node* head) {
    Node* newNode = new Node[sizeof(Node)];
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return head;
}

//print double linked list from head
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

//print double linked list from tail
void printListFromTail(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << temp->name << " " << temp->type << " " << temp->minTemp << " " << temp->maxTemp << endl;
        temp = temp->prev;
    }
}

//search double linked list by name from start and print
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

//search double linked list by name from tail and print
Node* searchListFromTail(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return head;
    }
    string name;
    cout << "¬ведите им€: ";
    cin >> name;
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        if (current->name == name) {
            cout << current->name << " " << current->type << " " << current->minTemp << " " << current->maxTemp << endl;
            return current;
        }
        current = current->prev;
    }
    cout << "Ёлемент не найден" << endl;
    return NULL;
}

//add node to double linked list by position
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
    Node* current = head;
    if (position < 0 || position > getLength(head)) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = current;
    }
    return head;
}

//detele node from double list by position
Node* deleteNode(Node* head) {
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
    //delete first node
    if (position == 0) {
        head = current->next;
    }
    //delete last node
    else if (position == getLength(head) - 1) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->prev->next = NULL;
    }
    //delete node in middle
    else {
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        current->next->prev = current;
    }
    return head;
}

//sort double linked list by name
Node* sortList(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return head;
    }
    Node* current = head;
    while (current->next != NULL) {
        Node* temp = current->next;
        while (temp != NULL) {
            if (current->name > temp->name) {
                string name = current->name;
                char type = current->type;
                float minTemp = current->minTemp;
                float maxTemp = current->maxTemp;
                current->name = temp->name;
                current->type = temp->type;
                current->minTemp = temp->minTemp;
                current->maxTemp = temp->maxTemp;
                temp->name = name;
                temp->type = type;
                temp->minTemp = minTemp;
                temp->maxTemp = maxTemp;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

//write double linked list to file
void writeList(Node* head) {
    if (head == NULL) {
        cout << "—писок пуст" << endl;
        return;
    }
    ofstream file;
    file.open("list.txt");
    Node* current = head;
    while (current != NULL) {
        file << current->name << " " << current->type << " " << current->minTemp << " " << current->maxTemp << endl;
        current = current->next;
    }
    file.close();
}

//read double linked list from file
Node* readList(Node* head) {
    ifstream file;
    file.open("list.txt");
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
        newNode->prev = NULL;
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    file.close();
    return head;
}
