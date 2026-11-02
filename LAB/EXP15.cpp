#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[1000];
    int shift, i, top;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if (top > 26) top = 26;

    for (shift = 0; shift < top; shift++) {
        printf("Shift %2d: ", shift);

        for (i = 0; cipher[i]; i++) {
            if (isalpha((unsigned char)cipher[i])) {
                char base = isupper(cipher[i]) ? 'A' : 'a';
                putchar((cipher[i] - base - shift + 26) % 26 + base);
            } else {
                putchar(cipher[i]);
            }
        }
    }

    return 0;
}