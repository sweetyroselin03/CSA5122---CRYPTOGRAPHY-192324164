#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char key[100], text[500], m[25];
    int used[26] = {0}, n = 0;
    printf("Enter Playfair keyword: ");
    scanf("%99s", key);
    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I';
        if (c >= 'A' && c <= 'Z' && !used[c-'A']) {
            m[n++] = c;
            used[c-'A'] = 1;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c-'A']) {
            m[n++] = c;
            used[c-'A'] = 1;
        }
    }
    printf("Enter ciphertext (no spaces): ");
    scanf("%499s", text);
    for (int i = 0; text[i] && text[i+1]; i += 2) {
        char a = toupper(text[i]);
        char b = toupper(text[i+1]);
        int r1=0,c1=0,r2=0,c2=0;
        for (int x = 0; x < 25; x++) {
            if (m[x] == a) r1=x/5, c1=x%5;
            if (m[x] == b) r2=x/5, c2=x%5;
        }
        if (r1 == r2) {
            a = m[r1*5 + (c1+4)%5];
            b = m[r2*5 + (c2+4)%5];
        } else if (c1 == c2) {
            a = m[((r1+4)%5)*5 + c1];
            b = m[((r2+4)%5)*5 + c2];
        } else {
            char t = m[r1*5+c2];
            b = m[r2*5+c1];
            a = t;
        }
        printf("%c%c", a, b);
    }
    printf("\n");
    return 0;
}
