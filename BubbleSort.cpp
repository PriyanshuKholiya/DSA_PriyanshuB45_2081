#include <stdio.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;

void inputArray();
void bubbleSort();
void printArray();

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size! Size should be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements of the array:\n", size);
    inputArray();

    printf("\nArray before sorting:\n");
    printArray();

    bubbleSort();

    printf("\nArray after sorting:\n");
    printArray();

    return 0;
}

void inputArray() {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void bubbleSort() {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray() {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
