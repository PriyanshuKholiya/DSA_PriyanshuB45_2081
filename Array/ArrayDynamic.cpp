int *array;
int size = 0;

void createArray() {
    printf("Enter the size of the array: ");  
    scanf("%d", &size);  // Input array size
    array = (int *)malloc(size * sizeof(int));  // Allocate memory for array
    printf("Enter %d elements:\n", size);  
    for (int i = 0; i < size; i++) {  //input array elements
        scanf("%d", &array[i]);  
    }
}

void displayArray() {
    if (size == 0) {  // Check if array is empty
        printf("Array is empty\n");  
        return;
    }
    printf("Array elements are:\n");  
    for (int i = 0; i < size; i++) {  // display array elements from index 0 to size-1
        printf("%d ", array[i]);  // Display array elements
    }
    printf("\n");
}

void insertBeginning() {
    size++;  // Increment size
    array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to accommodate new element
    printf("Enter the element to insert at the beginning: ");  
    scanf("%d", &array[size - 1]);  // Input element to insert at the beginning
    for (int i = size - 1; i > 0; i--) {  // Shift existing elements to the right
        array[i] = array[i - 1];  
    }
}

void insertEnd() {
    size++;  // Increment size
    array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to accommodate new element
    printf("Enter the element to insert at the end: ");  
    scanf("%d", &array[size - 1]);  // Input element to insert at the end
}

void insertAtPosition() {
    int pos;
    printf("Enter the position to insert the element: ");  
    scanf("%d", &pos);  // Input position to insert element
    if (pos < 1 || pos > size + 1) {  // Check for valid position
        printf("Invalid position\n");  
        return;
    }
    size++;  // Increment size
    array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to accommodate new element
    printf("Enter the element to insert: ");  
    scanf("%d", &array[pos - 1]);  // Input element to insert
}

void insertAfterElement() {
    int ele;
    printf("Enter the element after which you want to insert: ");  
    scanf("%d", &ele);  // Input element after which to insert
    for (int i = 0; i < size; i++) {  // Loop to search for element
        if (array[i] == ele) {  // Check if element is found
            size++;  // Increment size
            array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to accommodate new element
            printf("Enter the element to insert: ");  // Prompt for element to insert
            scanf("%d", &array[i + 1]);  // Input element to insert after specified element
            return;
        }
    }
    printf("Element not found\n");  // Print message if specified element is not found
}

void insertBeforeElement() {
    int ele;
    printf("Enter the element before which you want to insert: ");  // Prompt for element before which to insert
    scanf("%d", &ele);  // Input element before which to insert
    int index = -1;  // Initialize index variable to track position of element
    for (int i = 0; i < size; i++) {  // Loop to search for element
        if (array[i] == ele) {  // Check if element is found
            index = i;  // Store index of element
            break;
        }
    }
    if (index == -1) {  // Check if element is not found
        printf("Element not found\n");  // Print message if element is not found
        return;
    }
    size++;  // Increment size
    array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to accommodate new element
    if (array == NULL) {  // Check if memory allocation failed
        printf("Memory allocation failed\n");  // Print message if memory allocation failed
        exit(1);  // Exit program
    }
    for (int i = size - 1; i > index; i--) {  // Shift elements to the right
        array[i] = array[i - 1];  // Shift elements
    }
    printf("Enter the element to insert: ");  // Prompt for element to insert
    scanf("%d", &array[index]);  // Input element to insert before specified element
}

void deleteBeginning() {
    if (size == 0) {  // Check if array is empty
        printf("Array is empty\n");  // Print message if array is empty
        return;
    }
    for (int i = 0; i < size - 1; i++) {  // Loop to shift elements
        array[i] = array[i + 1];  // Shift elements to the left
    }
    size--;  // Decrement size
    array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to remove deleted element
}

void deleteEnd() {
    if (size == 0) {  // Check if array is empty
        printf("Array is empty\n");  // Print message if array is empty
        return;
    }
    size--;  // Decrement size
    array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to remove deleted element
}

void deleteAtPosition() {
    int pos;
    printf("Enter the position to delete: ");  
    scanf("%d", &pos);  // Input position to delete element
    if (pos < 1 || pos > size) {  
        printf("Invalid position\n");  // Print message for invalid position
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {  
        array[i] = array[i + 1];  // Shift elements to the left
    }
    size--;  // Decrement size
    array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to remove deleted element
}

void deleteAfterElement() {
    int ele;
    printf("Enter the element after which you want to delete: ");  // Input element after which to delete
    scanf("%d", &ele);  
    for (int i = 0; i < size - 1; i++) {  // Loop to search for element linearly
        if (array[i] == ele) {  
            for (int j = i + 1; j < size - 1; j++) {  
                array[j] = array[j + 1];  // Shift elements to the left
            }
            size--;  // Decrement size
            array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to remove deleted element
            return;
        }
    }
    printf("Element not found\n");  // Print message if specified element is not found
}

void deleteBeforeElement() {
    int ele;
    printf("Enter the element before which you want to delete: ");  //Input element before which to delete
    scanf("%d", &ele);  
    for (int i = 1; i < size; i++) {  // Loop to search for element linearly
        if (array[i] == ele) {  //if element is found
            for (int j = i - 1; j < size - 1; j++) {  
                array[j] = array[j + 1];  // Shift elements to the left
            }
            size--;  // Decrement size
            array = (int *)realloc(array, size * sizeof(int));  // Reallocate memory to remove deleted element
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
    
