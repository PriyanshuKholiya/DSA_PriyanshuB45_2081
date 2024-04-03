#include <stdio.h>

int main() {
    char alphabets[] = "abcdefghijklmnopqrstuvwxyz";
    int i, j;
    char temp;

    // Sorting alphabets using bubble sort algorithm
    for (i = 0; i < 25; i++) {
        for (j = 0; j < 25 - i; j++) {
            if (alphabets[j] > alphabets[j + 1]) {
                // Swap characters
                temp = alphabets[j];
                alphabets[j] = alphabets[j + 1];
                alphabets[j + 1] = temp;
            }
        }
    }

    // Printing sorted alphabets
    printf("Sorted Alphabets: ");
    for (i = 0; i < 26; i++) {
        printf("%c ", alphabets[i]);
    }
    printf("\n");

    return 0;
}

