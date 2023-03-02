#include <stdio.h>
#include <string.h>

// Function to convert a character to uppercase
char toUpperCase(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return ch - ('a' - 'A');
    }
    return ch;
}

// Function to encrypt a message using Hill Cipher
void encrypt(char *message, int key[3][3])
{
    int len = strlen(message);
    int i, j, k, sum;
    int plaintext[3], ciphertext[3];

    // Pad the message with 'X' to make its length a multiple of 3
    while (len % 3 != 0) {
        message[len++] = 'X';
    }

    // Convert the message to uppercase
    for (i = 0; i < len; i++) {
        message[i] = toUpperCase(message[i]);
    }

    // Encrypt the message block by block
    for (i = 0; i < len; i += 3) {
        // Extract the plaintext block
        for (j = 0; j < 3; j++) {
            plaintext[j] = message[i+j] - 'A';
        }
        // Encrypt the plaintext block using the key
        for (j = 0; j < 3; j++) {
            sum = 0;
            for (k = 0; k < 3; k++) {
                sum += key[j][k] * plaintext[k];
            }
            ciphertext[j] = sum % 26;
        }
        // Print the ciphertext block
        for (j = 0; j < 3; j++) {
            printf("%c", ciphertext[j] + 'A');
        }
    }
    printf("\n");
}

int main()
{
    char message[100];
    int key[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    int i;

    printf("Enter message to encrypt: ");
gets(message);
    printf("Uppercase Message: ");
    for ( i = 0; message[i]; i++) {
        printf("%c", toUpperCase(message[i]));
    }
    printf("\n");

    printf("Encrypted Message: ");
    encrypt(message, key);

    return 0;
}

