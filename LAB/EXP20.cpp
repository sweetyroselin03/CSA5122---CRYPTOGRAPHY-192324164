#include <stdio.h>

int main() {
    printf("ECB MODE:\n");
    printf("An error in ciphertext block C1 affects only plaintext P1.\n");
    printf("All other plaintext blocks remain unaffected.\n\n");

    printf("CBC MODE:\n");
    printf("a. An error in C1 corrupts P1 and flips corresponding bits in P2.\n");
    printf("   Blocks P3 onward are unaffected.\n\n");

    printf("b. An error in source plaintext P1:\n");
    printf("   It affects ciphertext C1 and propagates through subsequent blocks.\n");
    printf("   With CBC, all subsequent ciphertext blocks can be affected.\n");
    printf("   The receiver's plaintext blocks may consequently be corrupted.\n");

    return 0;
}