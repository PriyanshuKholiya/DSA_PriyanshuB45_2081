#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void createArray(int *array, int *size);
void displayArray(int *array, int size);
void insertBeginning(int *array, int *size);
void insertEnd(int *array, int *size);
void insertAtPosition(int *array, int *size, int position);
void insertAfterElement(int *array, int *size, int afterElement);
void insertBeforeElement(int *array, int *size, int beforeElement);
void deleteBeginning(int *array, int *size);
void deleteEnd(int *array, int *size);
void deleteAtPosition(int *array, int *size, int position);
void deleteAfterElement(int *array, int *size, int afterElement);
void deleteBeforeElement(int *array, int *size, int beforeElement);

int main() {
    int array[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printf("\nArray Operations Menu\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Insert After Element\n");
        printf("7. Insert Before Element\n");
        printf("8. Delete Beginning\n");
        printf("9. Delete End\n");
        printf("10. Delete at Position\n");
        printf("11. Delete After Element\n");
        printf("12. Delete Before Element\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createArray(array, &size);
                break;
            case 2:
                displayArray(array, size);
                break;
            case 3:
                insertBeginning(array, &size);
                break;
            case 4:
                insertEnd(array, &size);
                break;
            case 5: {
                int position;
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(array, &size, position);
                break;
            }
            case 6: {
                int afterElement;
                printf("Enter element after which to insert: ");
                scanf("%d", &afterElement);
                insertAfterElement(array, &size, afterElement);
                break;
            }
            case 7: {
                int beforeElement;
                printf("Enter element before which to insert: ");
                scanf("%d", &beforeElement);
                insertBeforeElement(array, &size, beforeElement);
                break;
            }
            case 8:
                deleteBeginning(array, &size);
                break;
            case 9:
                deleteEnd(array, &size);
                break;
            case 10: {
                int position;
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(array, &size, position);
                break;
            }
            case 11: {
                int afterElement;
                printf("Enter element after which to delete: ");
                scanf("%d", &afterElement);
                deleteAfterElement(array, &size, afterElement);
                break;
            }
            case 12: {
                int beforeElement;
                printf("Enter element before which to delete: ");
                scanf("%d", &beforeElement);
                deleteBeforeElement(array, &size, beforeElement);
                break;
            }
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 13.\n");
        }
    } while(choice != 13);

    return 0;
}

void createArray(int *array, int *size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);
    if (*size <= 0 || *size > MAX_SIZE) {
        printf("Invalid size! Size should be between 1 and %d.\n", MAX_SIZE);
        return;
    }
    printf("Enter array elements:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Array created successfully.\n");
}

void displayArray(int *array, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertBeginning(int *array, int *size) {
    int element;
    if (*size == MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);
    (*size)++;
    for (int i = *size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = element;
    printf("Element inserted at the beginning successfully.\n");
}

void insertEnd(int *array, int *size) {
    int element;
    if (*size == MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);
    (*size)++;
    array[*size - 1] = element;
    printf("Element inserted at the end successfully.\n");
}

void insertAtPosition(int *array, int *size, int position) {
    int element;
    if (*size == MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    (*size)++;
    for (int i = *size - 1; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = element;
    printf("Element inserted at position %d successfully.\n", position);
}

void insertAfterElement(int *array, int *size, int afterElement) {
    int element;
    if (*size >= MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);
    for (int i = 0; i < *size; i++) {
        if (array[i] == afterElement) {
            for (int j = *size; j > i + 1; j--) {
                array[j] = array[j - 1];
            }
            array[i + 1] = element;
            (*size)++;
            printf("Element %d inserted after %d successfully.\n", element, afterElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", afterElement);
}

void insertBeforeElement(int *array, int *size, int beforeElement) {
    int element;
    if (*size >= MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);
    for (int i = 0; i < *size; i++) {
        if (array[i] == beforeElement) {
            for (int j = *size; j > i; j--) {
                array[j] = array[j - 1];
            }
            array[i] = element;
            (*size)++;
            printf("Element %d inserted before %d successfully.\n", element, beforeElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", beforeElement);
}

void deleteBeginning(int *array, int *size) {
    if (*size == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
    printf("Element deleted from the beginning successfully.\n");
}

void deleteEnd(int *array, int *size) {
    if (*size == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    (*size)--;
    printf("Element deleted from the end successfully.\n");
}

void deleteAtPosition(int *array, int *size, int position) {
    if (*size == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
    printf("Element deleted from position %d successfully.\n", position);
}

void deleteAfterElement(int *array, int *size, int afterElement) {
    if (*size == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        if (array[i] == afterElement) {
            for (int j = i + 1; j < *size - 1; j++) {
                array[j] = array[j + 1];
            }
            (*size)--;
            printf("Element deleted after %d successfully.\n", afterElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", afterElement);
}

void deleteBeforeElement(int *array, int *size, int beforeElement) {
    if (*size == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    for (int i = 0; i < *size; i++) {
        if (array[i] == beforeElement) {
            for (int j = i - 1; j < *size - 1; j++) {
                array[j] = array[j + 1];
            }
            (*size)--;
            printf("Element deleted before %d successfully.\n", beforeElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", beforeElement);
}

