#include <stdio.h>
#include <ctype.h>
int main() {
    char text[200];
    char key[] = "CIPHER";
    char cipher[27];
    int used[26] = {0}, n = 0;
    for (int i = 0; key[i]; i++) {
        int x = toupper(key[i]) - 'A';
        if (!used[x]) {
            cipher[n++] = 'A' + x;
            used[x] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!used[i])
            cipher[n++] = 'A' + i;
    }
    cipher[26] = '\0';
    printf("Cipher alphabet: %s\n", cipher);
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    for (int i = 0; text[i]; i++) {
        if (isupper(text[i]))
            text[i] = cipher[text[i] - 'A'];
        else if (islower(text[i]))
            text[i] = cipher[text[i] - 'a'] + ('a' - 'A');
    }
    printf("Ciphertext: %s", text);
    return 0;
}
