#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[2000];
    char freq[] = "etaoinshrdlcumwfgypbvkjxqz";
    int count[26] = {0};
    int order[26], i, j, temp;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    for (i = 0; cipher[i]; i++)
        if (isalpha((unsigned char)cipher[i]))
            count[tolower(cipher[i]) - 'a']++;

    for (i = 0; i < 26; i++) order[i] = i;

    for (i = 0; i < 26; i++)
        for (j = i + 1; j < 26; j++)
            if (count[order[j]] > count[order[i]]) {
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }

    char map[26];

    for (i = 0; i < 26; i++)
        map[order[i]] = freq[i];

    printf("Approximate plaintext:\n");

    for (i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            char x = map[tolower(cipher[i]) - 'a'];
            putchar(isupper(cipher[i]) ? toupper(x) : x);
        } else {
            putchar(cipher[i]);
        }
    }

    return 0;
}