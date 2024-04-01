#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;//to check underflow

void createArray();
void displayArray();
void insertBeginning();
void insertEnd();
void insertAtPosition();
void insertAfterElement();
void insertBeforeElement();
void deleteBeginning();
void deleteEnd();
void deleteAtPosition();
void deleteAfterElement();
void deleteBeforeElement();

int main() {
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
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                insertBeginning();
                break;
            case 4:
                insertEnd();
                break;
            case 5:
                insertAtPosition();
                break;
            case 6:
                insertAfterElement();
                break;
            case 7:
                insertBeforeElement();
                break;
            case 8:
                deleteBeginning();
                break;
            case 9:
                deleteEnd();
                break;
            case 10:
                deleteAtPosition();
                break;
            case 11:
                deleteAfterElement();
                break;
            case 12:
                deleteBeforeElement();
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 13.\n");
        }
    } while(choice != 13);

    return 0;
}

void createArray() {
    int i;
    printf("Enter the size of the array: ");//input size
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {//check if size is negative or greater than max size
        printf("Invalid size! Size should be between 1 and %d.\n", MAX_SIZE);
        return;
    }
    printf("Enter array elements:\n");//loop to input elements 
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Array created successfully.\n");
}

void displayArray() {
    int i;
    if (size == 0) {//no elements
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < size; i++) {//loop to print elements
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertBeginning() {
    int element;
    if (size == MAX_SIZE) {//overflow
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");//input element
    scanf("%d", &element);
    size++;//increase the size of array
    for (int i = size; i > 0; i--) {//right shift till first element
        array[i] = array[i - 1];
    }
    array[0] = element;//input the element in the first position
    
    printf("Element inserted at the beginning successfully.\n");
}

void insertEnd() {
    int element;
    if (size == MAX_SIZE) {//overflow
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");//input element
    scanf("%d", &element);
    size++;//increase size of array to accomodate new element
    array[size-1] = element;//input the element at the last index
    
    printf("Element inserted at the end successfully.\n");
}

void insertAtPosition() {
    int element, position;
    if (size == MAX_SIZE) {//overflow
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");//input element
    scanf("%d", &element);
    printf("Enter position to insert: ");//input position
    scanf("%d", &position);
    if (position < 0 || position >= size) {//check if the position is negative or greater than equal to size 
        printf("Invalid position!\n");
        return;
    }
	  size++;//increase the size of array to accomodate new element
    for (int i = size-1; i >= position; i--) {//loop from last index to the position entered tp right shift elements
        array[i] = array[i - 1];
    }
    array[position-1] = element;//assign the element at position
  
    printf("Element inserted at position %d successfully.\n", position);
}

void insertAfterElement() {
    int afterElement, element;
    if (size >= MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element after which to insert: ");
    scanf("%d", &afterElement);
    printf("Enter element to insert: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++) {
        if (array[i] == afterElement) {
            for (int j = size; j > i + 1; j--) {
                array[j] = array[j - 1];
            }
            array[i + 1] = element;
            size++;
            printf("Element %d inserted after %d successfully.\n", element, afterElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", afterElement);
}

void insertBeforeElement() {
    int beforeElement, element;
    if (size >= MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    printf("Enter element before which to insert: ");
    scanf("%d", &beforeElement);
    printf("Enter element to insert: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++) {
        if (array[i] == beforeElement) {
            for (int j = size; j > i; j--) {
                array[j] = array[j - 1];
            }
            array[i] = element;
            size++;
            printf("Element %d inserted before %d successfully.\n", element, beforeElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", beforeElement);
}


void deleteBeginning() {
    if (size == 0) {//underflow
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {//left shift from index 0 till n-1
        array[i] = array[i + 1];
    }
    size--;//update size
    printf("Element deleted from the beginning successfully.\n");
}

void deleteEnd() {
	if (size == 0) {//underflow
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    size--;//decreasing the size will automatically remove the last element
    printf("Element deleted from the end successfully.\n");
}

void deleteAtPosition() {
    int position;
    if (size == 0) {//underflow
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    printf("Enter position to delete: ");//input position
    scanf("%d", &position);
    if (position < 0 || position >= size) {//position is negative or greater than equal to size
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < size - 1; i++) {//left shift from position to the last index
        array[i] = array[i + 1];
    }
    size--;//update size of the array
    printf("Element deleted from position %d successfully.\n", position);
}

void deleteAfterElement() {
	 int afterElement;
    printf("Enter element after which to delete: ");
    scanf("%d", &afterElement);
    for (int i = 0; i < size - 1; i++) {
        if (array[i] == afterElement) {
            for (int j = i + 1; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            size--;
            printf("Element deleted after %d successfully.\n", afterElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", afterElement);
}

void deleteBeforeElement() {
	int beforeElement;
    printf("Enter element before which to delete: ");
    scanf("%d", &beforeElement);
    for (int i = 0; i < size; i++) {
        if (array[i] == beforeElement) {
            for (int j = i - 1; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            size--;
            printf("Element deleted before %d successfully.\n", beforeElement);
            return;
        }
    }
    printf("Element %d not found in the array.\n", beforeElement);
}

