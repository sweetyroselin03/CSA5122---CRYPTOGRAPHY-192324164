#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char text[100];
    int k;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key (1-25): ");
    scanf("%d", &k);
    if (k < 1 || k > 25) {
        printf("Invalid key!");
        return 0;
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            text[i] = (text[i] - 'A' + k) % 26 + 'A';
        else if (islower(text[i]))
            text[i] = (text[i] - 'a' + k) % 26 + 'a';
    }
    printf("Ciphertext: %s", text);
    return 0;
}
