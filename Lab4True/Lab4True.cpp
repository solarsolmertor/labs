#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main(void) {
    /* setting russian locale */
    setlocale(LC_ALL, "RUS");

    /* setting data */
    char number; // number of node
    char priority; // priority of message
    char user; // user id
    unsigned int UnitStateWord; // decoded word

    /* input data */
    printf("Enter number of node (0 - 31) > ");
    scanf("%d", &number);
    printf("Enter priority of message (0 - 63) > ");
    scanf("%d", &priority);
    printf("Enter user ID (0 - 31) > ");
    scanf("%d", &user);

    /* encode data */
    UnitStateWord = ((unsigned int)number & 0x1F) << 12;
    UnitStateWord |= ((unsigned int)priority & 0x3F) << 8;
    UnitStateWord |= user & 0x1F;

    /* result of encoding */
    printf("\nEncoded word = %04x\n",
        UnitStateWord);
    printf("Ented unit State Word (Hexadecimal number from 0 to 0xFFFF) > ");
    scanf("%x", &UnitStateWord);

    /* decode data */
    UnitStateWord = (number >> 12) & 0x1F;
    UnitStateWord = (priority >> 8) & 0x3F;
    UnitStateWord = user & 0x1F;

    /* result of decoding */
    putchar('\n');
    printf("Number of node = %d\t\n", number);
    printf("Priority of message = %d\t\n", priority);
    printf("User ID = %d\t\n", user);
    system("pause");
    return 0;
}
