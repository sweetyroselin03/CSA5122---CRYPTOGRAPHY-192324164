#include <stdio.h>

int main() {
    int i;
    int shift[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

    printf("DES decryption key schedule:\n");

    for (i = 15; i >= 0; i--)
        printf("Decryption round %2d uses K%d\n", 16 - i, i + 1);

    printf("\nReverse the encryption round keys: K16 to K1.\n");
    printf("Shift schedule is reversed for decryption key generation.\n");

    return 0;
}