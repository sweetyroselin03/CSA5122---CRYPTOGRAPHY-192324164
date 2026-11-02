#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char key[100], text[200], matrix[25];
    int used[26] = {0}, n = 0;
    printf("Enter keyword: ");
    scanf("%99s", key);
    printf("Enter plaintext: ");
    scanf(" %199[^\n]", text);
    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I';
        if (c >= 'A' && c <= 'Z' && !used[c-'A']) {
            matrix[n++] = c;
            used[c-'A'] = 1;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c-'A']) {
            matrix[n++] = c;
            used[c-'A'] = 1;
        }
    }
    char p[200];
    int m = 0;
    for (int i = 0; text[i]; i++) {
        char c = toupper(text[i]);
        if (c < 'A' || c > 'Z') continue;
        if (c == 'J') c = 'I';

        p[m++] = c;
    }
    char out[400];
    int j = 0;
    for (int i = 0; i < m;) {
        char a = p[i++];
        char b;
        if (i >= m) b = 'X';
        else if (p[i] == a) b = 'X';
        else b = p[i++];
        int r1, c1, r2, c2;
        for (int x = 0; x < 25; x++) {
            if (matrix[x] == a) {
                r1 = x / 5; c1 = x % 5;
            }
            if (matrix[x] == b) {
                r2 = x / 5; c2 = x % 5;
            }
        }
        if (r1 == r2) {
            out[j++] = matrix[r1*5 + (c1+1)%5];
            out[j++] = matrix[r2*5 + (c2+1)%5];
        } else if (c1 == c2) {
            out[j++] = matrix[((r1+1)%5)*5 + c1];
            out[j++] = matrix[((r2+1)%5)*5 + c2];
        } else {
            out[j++] = matrix[r1*5 + c2];
            out[j++] = matrix[r2*5 + c1];
        }
    }
    out[j] = '\0';
    printf("Ciphertext: %s\n", out);
    return 0;
}
