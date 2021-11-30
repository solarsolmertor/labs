#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));
    const int size = 100;
    int Arr[size];

    int r, temp, pos, i;
    // заполнение массива
    for (int i = 0; i < size; i++)
    {
        r = rand() % 200;
        r -= 100;
        Arr[i] = r;
    }

    printf("Size: %d\nArray before transformation:\n", size);

    for (i = 0; i < size; i++)
    {
        printf("%d ", Arr[i]);
    }

    // сортировка массива
    int j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
    }
    // после сортировки числа больше нуля будут на своем месте
    // осталось поменять местами отрицательные с нулевыми
    pos = size;
    // определяется позиция первого положительного
    for (i = 0; i < size; i++)
        if (Arr[i] > 0)
        {
            pos = i;
            break;
        }

    for (i = 0; i < pos; i++)
    {
        for (j = 0; j < pos - 1; j++)
            if (Arr[j + 1] == 0)
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
    }

    printf("\n\nArray after transformation:\n");

    for (i = 0; i < size; i++)
    {
        printf("%d ", Arr[i]);
    }
    getchar();
    return 0;
}
