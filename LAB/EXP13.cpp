#include <stdio.h>

int main() {
    int p[2][2] = {{1, 0}, {0, 1}};
    int c[2][2] = {{9, 4}, {5, 7}};
    int i, j, k;

    printf("Known plaintext attack:\n");
    printf("Plaintext matrix P:\n");

    for (i = 0; i < 2; i++)
        printf("%d %d\n", p[i][0], p[i][1]);

    printf("Ciphertext matrix C:\n");

    for (i = 0; i < 2; i++)
        printf("%d %d\n", c[i][0], c[i][1]);

    printf("Recovered key K = C * inverse(P) mod 26:\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            int sum = 0;
            for (k = 0; k < 2; k++)
                sum += c[i][k] * p[k][j];

            printf("%d ", sum % 26);
        }
        printf("\n");
    }

    printf("Chosen plaintext attack: choose independent plaintext blocks.\n");
    return 0;
}