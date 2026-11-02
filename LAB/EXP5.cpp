#include <stdio.h>
#include <ctype.h>
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main() {
    char text[100];
    int a, b;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter keys a and b: ");
    scanf("%d %d", &a, &b);
    a = (a % 26 + 26) % 26;
    b = (b % 26 + 26) % 26;
    if (gcd(a, 26) != 1) {
        printf("Invalid key a!");
        return 0;
    }
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int p = text[i] - base;
            text[i] = (a * p + b) % 26 + base;
        }
    }
    printf("Ciphertext: %s", text);
    return 0;
}
