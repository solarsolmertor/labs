#pragma once
#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

#define PRINT_TYPE
#define DEBUG

using namespace std;

const int SIZE = 3;

struct Chemistry {
    char name[20];
    char type;
    char temperature[20];
};

void arrayFillingByHands(Chemistry arr[]);
void arrayFillingAuto(Chemistry arr[]);
void outPut(Chemistry arr[]);
void sort(Chemistry arr[]);

#endif

