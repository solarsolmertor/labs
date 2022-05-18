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
    Node* prev;
    Node* next;
};

int getLength(Node* head);
Node* createList(Node* head);
void printList(Node* head);
void printListFromTail(Node* head);
Node* searchList(Node* head);
Node* searchListFromTail(Node* head);
Node* addNode(Node* head);
Node* deleteNode(Node* head);
Node* sortList(Node* head);
void writeList(Node* head);
Node* readList(Node* head);

#endif

