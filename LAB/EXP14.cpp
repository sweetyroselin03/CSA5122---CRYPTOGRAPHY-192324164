#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char p[] = "send more money";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char c[100], target[] = "cash not needed";
    int i, j = 0, len = strlen(p);

    for (i = 0; i < len; i++) {
        if (isalpha((unsigned char)p[i])) {
            c[i] = (tolower(p[i]) - 'a' + key[j++]) % 26 + 'a';
        } else {
            c[i] = p[i];
        }
    }
    c[len] = '\0';

    printf("Ciphertext: %s\n", c);
    printf("Key to decrypt ciphertext as 'cash not needed': ");

    j = 0;
    for (i = 0; i < len; i++) {
        if (isalpha((unsigned char)p[i])) {
            int t = (tolower(target[i]) - 'a');
            int x = (c[i] - 'a' - t + 26) % 26;
            printf("%d ", x);
            j++;
        } else {
            printf("  ");
        }
    }

    printf("\n");
    return 0;
}