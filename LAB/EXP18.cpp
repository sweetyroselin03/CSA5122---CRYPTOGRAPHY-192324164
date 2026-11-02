#include <stdio.h>

int main() {
    int round, i;

    printf("DES subkey generation demonstration\n");

    for (round = 1; round <= 16; round++) {
        printf("Round %2d: First 24 bits from C, next 24 bits from D\n",
               round);

        for (i = 0; i < 24; i++)
            printf("%d ", i + 1);

        printf("| ");

        for (i = 0; i < 24; i++)
            printf("%d ", i + 29);

        printf("\n");
    }

    printf("Actual DES uses PC-2 to select 48 bits from 56 shifted bits.\n");
    return 0;
}