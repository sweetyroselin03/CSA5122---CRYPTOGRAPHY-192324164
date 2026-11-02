#include <stdio.h>
#include <string.h>

int main() {
    char p[128] = "HELLO CBC MODE";
    unsigned char c[128], iv = 0;
    int len = strlen(p), i;

    printf("CBC Mode Encryption (Demonstration)\n");

    for (i = 0; i < len; i++) {
        c[i] = (unsigned char)p[i] ^ iv;
        iv = c[i];
    }

    printf("Ciphertext: ");
    for (i = 0; i < len; i++)
        printf("%02X ", c[i]);

    printf("\n");
    return 0;
}