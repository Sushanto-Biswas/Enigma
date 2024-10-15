#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Other characters remain unchanged
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26)); // Decryption is just encryption with a negative shift
}

int main() {
    char text[100];
    int shift;
    int choice;

    printf("Choose 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
