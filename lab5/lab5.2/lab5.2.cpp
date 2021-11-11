#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    int mushrooms; // input value
    while (true) {
        printf("Введите количество грибов > ");
        scanf("%d", &mushrooms); // entering value
        if (mushrooms < 0) { // invalid number of mushrooms
            printf("Неправильные данные!\n");
            continue;
        }
        printf("Мы нашли %d", mushrooms);
        if (mushrooms % 100 > 10 && mushrooms % 100 < 15)
            printf(" грибов в лесу\n");
        else
        {
            if (mushrooms % 10 == 1)
                printf(" гриб в лесу\n");
            if (mushrooms % 10 > 1 && mushrooms % 10 < 5)
                printf(" гриба в лесу\n");
            if ((mushrooms % 10 > 4 && mushrooms % 10 < 10) || mushrooms % 10 == 0)
                printf(" грибов в лесу\n");
        }
    }
    return 0;
}
