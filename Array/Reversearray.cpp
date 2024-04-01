#include <stdio.h>

// Function to print elements of an array in reverse order
void printReverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[10];

    // Input 10 elements into the array
    printf("Enter 10 elements:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Print elements in reverse order
    printf("Elements in reverse order:\n");
    printReverse(arr, 10);

    return 0;
}
