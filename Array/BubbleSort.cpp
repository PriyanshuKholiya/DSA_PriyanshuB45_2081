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

    if (size <= 0 || size > MAX_SIZE) {//if size negative or greater than maxsize
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
    for (int i = 0; i < size; i++) {//input elements from index 0 to size-1
        scanf("%d", &array[i]);
    }
}

void bubbleSort() {
    int temp;  
    for (int i = 0; i < size - 1; i++) {  // Loop for number of rounds
        for (int j = 0; j < size - i - 1; j++) {  // Loop to compare adjacent elements
            if (array[j] > array[j + 1]) {  
                temp = array[j];  // Swap elements if they are in the wrong order
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


void printArray() {
    for (int i = 0; i < size; i++) {//print elements from index 0 to size-1
        printf("%d ", array[i]);
    }
    printf("\n");
}

