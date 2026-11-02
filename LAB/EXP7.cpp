#include <stdio.h>
#include <string.h>
int main() {
    char text[1000];
    int freq[256] = {0};
    printf("Enter ciphertext:\n");
    fgets(text, sizeof(text), stdin);
    for (int i = 0; text[i] != '\0'; i++)
        freq[(unsigned char)text[i]]++;
    printf("\nCharacter frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && i != '\n' && i != ' ')
            printf("'%c' : %d\n", i, freq[i]);
    }
    printf("\nUse frequency analysis and word patterns ");
    printf("to determine the substitution key.\n");
    return 0;
}
