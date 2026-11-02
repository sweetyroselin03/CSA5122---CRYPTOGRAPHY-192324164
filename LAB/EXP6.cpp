#include <stdio.h>
int main() {
    int a, b, p;
    char c;
    printf("Enter ciphertext letter (B or U): ");
    scanf(" %c", &c);
    printf("Enter a and b keys: ");
    scanf("%d %d", &a, &b);
    int inv = -1;
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            inv = i;
            break;
        }
    }
    if (inv == -1) {
        printf("Invalid affine key!");
        return 0;
    }
    int x = c - 'A';
    p = (inv * (x - b + 26)) % 26;
    printf("Decrypted letter: %c\n", 'A' + p);
    return 0;
}
