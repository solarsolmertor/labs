#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct Node {
    string name;
    char type;
    float minTemp;
    float maxTemp;
    Node* next;
};

int getLength(Node* head);
Node* createList(Node* head);
void printList(Node* head);
Node* searchList(Node* head);
Node* addNode(Node* head);
Node* removeNode(Node* head);
Node* sortList(Node* head);
void writeList(Node* head);
Node* createListFromFile(Node* head);

#endif