#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char p[] = "meet me at the usual place at ten rather than eight oclock";
    char text[200], cipher[200];
    int K[2][2] = {{9, 4}, {5, 7}};
    int inv[2][2] = {{7, 22}, {5, 9}};
    int i, a, b, len = 0;

    for (i = 0; p[i]; i++)
        if (isalpha((unsigned char)p[i]))
            text[len++] = tolower((unsigned char)p[i]);

    if (len % 2) text[len++] = 'x';
    text[len] = '\0';

    printf("Plaintext: %s\n", text);
    printf("Encrypted: ");

    for (i = 0; i < len; i += 2) {
        a = text[i] - 'a';
        b = text[i + 1] - 'a';
        cipher[i] = (K[0][0] * a + K[0][1] * b) % 26 + 'a';
        cipher[i + 1] = (K[1][0] * a + K[1][1] * b) % 26 + 'a';
        printf("%c%c", cipher[i], cipher[i + 1]);
    }

    cipher[len] = '\0';
    printf("\nDecrypted: ");

    for (i = 0; i < len; i += 2) {
        a = cipher[i] - 'a';
        b = cipher[i + 1] - 'a';
        printf("%c%c",
               (inv[0][0] * a + inv[0][1] * b) % 26 + 'a',
               (inv[1][0] * a + inv[1][1] * b) % 26 + 'a');
    }

    printf("\n");
    return 0;
}