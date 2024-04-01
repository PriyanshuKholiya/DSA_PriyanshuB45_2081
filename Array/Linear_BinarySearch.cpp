#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {//loop for passes,for each pass the greatest element is sorted at the highest index
        for (int j = 0; j < n - i - 1; j++) {//loop for comparisions
            if (arr[j] > arr[j + 1]) {//swap if index at lower index is greater than element at higher index
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int n, int key) {
    int flag = 0;//for case of failure
    for (int i = 0; i < n; i++) {//compare each element with the key
        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Element not found\n");
    }
}

void binarySearch(int arr[], int n, int key) {
    bubbleSort(arr, n);//sort the elements using bubble sort
    int li = 0, ui = n - 1, mid;
    while (li <= ui) {
        mid = (li + ui) / 2;
        if (arr[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            return;
        } else if (arr[mid] < key) {//discard elements on left if mid less than key 
            li = mid + 1;
        } else {//discard elements on right otherwise when mid is greater than key
            ui = mid - 1;
        }
    }
    printf("Element not found\n");
}

int main() {
    int *array;
    int size, choice, key;

    printf("Enter the size of the array: ");//input size
    scanf("%d", &size);

    array = (int *)malloc(size * sizeof(int));//allocating memory dynamically using malloc
    if (array == NULL) {//if memory was not allocated
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {//input elements
        scanf("%d", &array[i]);
    }

    do {
        printf("\n--- Search Menu ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        printf("\n----------------------");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to search: ");//input element to be searched
                scanf("%d", &key);
                linearSearch(array, size, key);
                break;
            case 2:
                printf("Enter the element to search: ");//input element to be searched
                scanf("%d", &key);
                binarySearch(array, size, key);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    free(array);
    return 0;
}


