#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char compareNumbers(int first, int second) {
    if (first > second) return '>';
    else if (first < second) return '<';
    else return '=';
}

int main() {
    int firstNumber, secondNumber;
    printf("Enter two numbers for comparing > ");
    scanf("%d %d", &firstNumber, &secondNumber);
    printf("%c\n", compareNumbers(firstNumber, secondNumber));
    return 0;
}
