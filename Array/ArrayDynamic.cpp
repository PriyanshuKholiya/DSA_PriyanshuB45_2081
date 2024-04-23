#include <stdio.h>
#include <stdlib.h>

int *array;
int size = 0;

void createArray() {
    printf("Enter the size of the array: ");//input size
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));//allocate memory equivalent to size times of size of an integer
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {//scan elements
        scanf("%d", &array[i]);
    }
}

void displayArray() {
    if (size == 0) {//array not initialized or empty 
        printf("Array is empty\n");
        return;
    }
    printf("Array elements are:\n");//traverse array
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertBeginning() {
    size++; // Increment size
    array = (int *)realloc(array, size * sizeof(int)); //reallocate memory according to new size
    printf("Enter the element to insert at the beginning: ");
    scanf("%d", &array[size - 1]); // Insert the new element at the end
    for (int i = size - 1; i > 0; i--) {
        array[i] = array[i - 1];// Shift existing elements to the right
    }
}

void insertEnd() {
    size++;
    array = (int *)realloc(array, size * sizeof(int));
    printf("Enter the element to insert at the end: ");
    scanf("%d", &array[size - 1]);
}

void insertAtPosition() {
    int pos;
    printf("Enter the position to insert the element: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position\n");
        return;
    }
    size++;
    array = (int *)realloc(array, size * sizeof(int));
    printf("Enter the element to insert: ");
    scanf("%d", &array[pos - 1]);
}

void insertAfterElement() {
    int ele;
    printf("Enter the element after which you want to insert: ");
    scanf("%d", &ele);
    for (int i = 0; i < size; i++) {
        if (array[i] == ele) {
            size++;
            array = (int *)realloc(array, size * sizeof(int));
            printf("Enter the element to insert: ");
            scanf("%d", &array[i + 1]);
            return;
        }
    }
    printf("Element not found\n");
}

void insertBeforeElement() {
    int ele;
    printf("Enter the element before which you want to insert: ");
    scanf("%d", &ele);

    // Find the index of the element
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] == ele) {
            index = i;
            break;
        }
    }

    // If element not found, return
    if (index == -1) {
        printf("Element not found\n");
        return;
    }

    // Increment size
    size++;
    // Reallocate memory to accommodate the new element
    array = (int *)realloc(array, size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Shift elements to the right
    for (int i = size - 1; i > index; i--) {
        array[i] = array[i - 1];
    }

    // Prompt for and insert the new element
    printf("Enter the element to insert: ");
    scanf("%d", &array[index]);
}

   
void deleteBeginning() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}

void deleteEnd() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}

void deleteAtPosition() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}

void deleteAfterElement() {
    int ele;
    printf("Enter the element after which you want to delete: ");
    scanf("%d", &ele);
    for (int i = 0; i < size - 1; i++) {
        if (array[i] == ele) {
            for (int j = i + 1; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            size--;
            array = (int *)realloc(array, size * sizeof(int));
            return;
        }
    }
    printf("Element not found\n");
}

void deleteBeforeElement() {
    int ele;
    printf("Enter the element before which you want to delete: ");
    scanf("%d", &ele);
    for (int i = 1; i < size; i++) {
        if (array[i] == ele) {
            for (int j = i - 1; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            size--;
            array = (int *)realloc(array, size * sizeof(int));
            return;
        }
    }
    printf("Element not found\n");
}

int main() {
    int choice;
    do {
        printf("\n----- Menu -----\n");
        printf("1. Create Array\n2. Display Array\n3. Insert at Beginning\n4. Insert at End\n5. Insert at Position\n");
        printf("6. Insert After Element\n7. Insert Before Element\n8. Delete Beginning\n9. Delete End\n");
        printf("10. Delete at Position\n11. Delete After Element\n12. Delete Before Element\n13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertBeginning(); break;
            case 4: insertEnd(); break;
            case 5: insertAtPosition(); break;
            case 6: insertAfterElement(); break;
            case 7: insertBeforeElement(); break;
            case 8: deleteBeginning(); break;
            case 9: deleteEnd(); break;
            case 10: deleteAtPosition(); break;
            case 11: deleteAfterElement(); break;
            case 12: deleteBeforeElement(); break;
            case 13: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 13);

    free(array);
    return 0;
}
