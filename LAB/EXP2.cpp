
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            text[i] = key[text[i] - 'A'];
        else if (islower(text[i]))
            text[i] = key[text[i] - 'a'] + ('a' - 'A');
    }

    printf("Ciphertext: %s", text);
    return 0;
}
