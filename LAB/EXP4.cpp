#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char text[200], key[100];
    int j = 0;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter keyword: ");
    scanf("%99s", key);
    int len = strlen(key);
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % len]) - 'A';

            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }
    printf("Ciphertext: %s", text);
    return 0;
}
