#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create();
void display();
void insert_beg();
void insert_end();
void insert_patloc();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_patloc();
void delete_before();
void delete_after();

int main() {
    int choice;

    do {
        printf("\n ----------------Doubly Circular Linked List Menu----------------");
        printf("\n 1. Create");
        printf("\n 2. Display");
        printf("\n 3. Insert element at beginning");
        printf("\n 4. Insert element at the end");
        printf("\n 5. Insert element at a particular location");
        printf("\n 6. Insert element before a specific element");
        printf("\n 7. Insert element after a specific element");
        printf("\n 8. Delete element at the beginning");
        printf("\n 9. Delete element at the end");
        printf("\n 10. Delete element at a particular location");
        printf("\n 11. Delete element before a specific element");
        printf("\n 12. Delete element after a specific element");
        printf("\n 13. Exit");
        printf("\n\n -------------------------------------------------------------");

        printf("\n Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert_beg(); break;
            case 4: insert_end(); break;
            case 5: insert_patloc(); break;
            case 6: insert_before(); break;
            case 7: insert_after(); break;
            case 8: delete_beg(); break;
            case 9: delete_end(); break;
            case 10: delete_patloc(); break;
            case 11: delete_before(); break;
            case 12: delete_after(); break;
        }
    } while(choice != 13);

    return 0;
}

void create() {
    int n;
    char ch;

    printf("\nEnter first element: ");
    scanf("%d", &n);

    // Create a new node for the first element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = NULL;
    head = newnode; // Set the head to point to the first node

    printf("\nDo you want to continue (y/n): ");
    scanf(" %c", &ch);

    // Continuously add new elements until user stops
    while(ch == 'y' || ch == 'Y') {
        printf("\nEnter next element: ");
        scanf("%d", &n);

        // Traverse to the last node
        struct node *temp = head;
        while(temp->next != head) { // Traverse until the last node is reached
            temp = temp->next;
        }

        // Create a new node for the next element
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = n;
        newnode->prev = temp;
        newnode->next = head;
        temp->next = newnode; // Update the next pointer of the last node to point to the new node
        head->prev = newnode; // Update the prev pointer of the head node to point to the new node
        head = newnode; // Update the head to point to the new node

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);
    }
}

void display() {
    if(head == NULL)
        printf("List is empty");
    else {
        struct node *temp = head;

        printf("Doubly Circular Linked List: ");
        do {
            printf("%d ", temp->data); // Print the data of the current node
            temp = temp->next; // Move to the next node
        } while(temp != head); // Continue until we reach back to the head
    }
}

void insert_beg() {
    int n;
    printf("\nEnter element to insert at the beginning: ");
    scanf("%d", &n);

    // Create a new node for the element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL) { // If the list is empty
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode; // Set head to point to the new node
    } else {
        newnode->next = head; // Set the next pointer of the new node to point to the current head
        newnode->prev = head->prev; // Set the prev pointer of the new node to point to the last node
        head->prev->next = newnode; // Update the next pointer of the last node to point to the new node
        head->prev = newnode; // Update the prev pointer of the head node to point to the new node
        head = newnode; // Update the head to point to the new node
    }
}

void insert_end() {
    int n;
    printf("\nEnter element to insert at the end: ");
    scanf("%d", &n);

    // Create a new node for the element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL) { // If the list is empty
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode; // Set head to point to the new node
    } else {
        newnode->next = head; // Set the next pointer of the new node to point to the current head
        newnode->prev = head->prev; // Set the prev pointer of the new node to point to the last node
        head->prev->next = newnode; // Update the next pointer of the last node to point to the new node
        head->prev = newnode; // Update the prev pointer of the head node to point to the new node
    }
}

void insert_patloc() {
    int n, pos, i = 1;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter element to insert: ");
    scanf("%d", &n);

    printf("Enter position at which the node is to be inserted: ");
    scanf("%d", &pos);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;

    // Traverse to the specified position
    struct node *temp = head;
    while(i < pos && temp != head) { // Traverse until reaching the specified position
        temp = temp->next;
        i++;
    }

    // If position is out of range
    if(temp == head) {
        printf("Position out of range");
        return;
    }

    // Update pointers to insert the new node at the specified position
    newnode->next = temp; // Set the next pointer of the new node to point to the current node at the position
    newnode->prev = temp->prev; // Set the prev pointer of the new node to point to the node before the current node
    temp->prev->next = newnode; // Update the next pointer of the node before the current node to point to the new node
    temp->prev = newnode; // Update the prev pointer of the current node to point to the new node
}

void insert_before() {
    int n, elebef;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter the element you want to insert: ");
    scanf("%d", &n);

    printf("Enter the element before which you want to insert: ");
    scanf("%d", &elebef);

    // Create a new node for the element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;

    // Traverse to the specific element
    struct node *temp = head;
    while(temp != NULL && temp->data != elebef) { // Traverse until reaching the specified element
        temp = temp->next;
    }

    // If specified element is not found
    if(temp == NULL) {
        printf("Element %d not found in the list", elebef);
        return;
    }

    // Update pointers to insert the new node before the specified element
    if(temp->prev == NULL) { // If the specified element is the first node
        newnode->next = temp;
        newnode->prev = NULL;
        temp->prev = newnode;
        head = newnode;
    } else {
        newnode->next = temp; // Set the next pointer of the new node to point to the specified element
        newnode->prev = temp->prev; // Set the prev pointer of the new node to point to the node before the specified element
        temp->prev->next = newnode; // Update the next pointer of the node before the specified element to point to the new node
        temp->prev = newnode; // Update the prev pointer of the specified element to point to the new node
    }
}

void insert_after() {
    int n, eleaft;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter the element you want to insert: ");
    scanf("%d", &n);

    printf("Enter the element after which you want to insert: ");
    scanf("%d", &eleaft);

    // Create a new node for the element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;

    // Traverse to the specific element
    struct node *temp = head;
    while(temp != NULL && temp->data != eleaft) { // Traverse until reaching the specified element
        temp = temp->next;
    }

    // If specified element is not found
    if(temp == NULL) {
        printf("Element %d not found in the list", eleaft);
        return;
    }

    // Update pointers to insert the new node after the specified element
    if(temp->next == NULL) { // If the specified element is the last node
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
    } else {
        newnode->next = temp->next; // Set the next pointer of the new node to point to the node after the specified element
        newnode->prev = temp; // Set the prev pointer of the new node to point to the specified element
        temp->next->prev = newnode; // Update the prev pointer of the node after the specified element to point to the new node
        temp->next = newnode; // Update the next pointer of the specified element to point to the new node
    }
}

void delete_beg() {
    if(head == NULL) {
        printf("List is empty");
        return;
    }

    struct node *temp = head;
    if(temp->next == head) { // If there's only one node in the list
        head = NULL; // Set head to NULL
    } else {
        head->prev->next = head->next; // Update the next pointer of the last node to point to the second node
        head->next->prev = head->prev; // Update the prev pointer of the second node to point to the last node
        head = head->next; // Move head to the second node
    }

    free(temp); // Free the memory of the deleted node
}

void delete_end() {
    if(head == NULL) {
        printf("List is empty");
        return;
    }

    struct node *temp = head->prev; // Point to the last node

    if(temp == head) { // If there's only one node in the list
        head = NULL; // Set head to NULL
    } else {
        temp->prev->next = head; // Update the next pointer of the second-to-last node to point to the head
        head->prev = temp->prev; // Update the prev pointer of the head node to point to the second-to-last node
    }

    free(temp); // Free the memory of the deleted node
}

void delete_patloc() {
    int pos, i = 1;

    if(head == NULL) { // If the list is empty
        printf("List is empty");
        return;
    }

    printf("\nEnter the position of element to be deleted: ");
    scanf("%d", &pos);

    struct node *temp = head;
    while(i < pos && temp != NULL) { // Traverse until reaching the specified position or the end of the list
        temp = temp->next;
        i++;
    }

    if(temp == NULL) { // If position is out of range
        printf("Position out of range");
        return;
    }

    if(temp->prev == NULL) { // If the node to be deleted is the head node
        head = temp->next; // Update head to point to the next node
    } else {
        temp->prev->next = temp->next; // Update the next pointer of the previous node to skip the node to be deleted
    }

    if(temp->next != NULL) { // If the node to be deleted is not the last node
        temp->next->prev = temp->prev; // Update the prev pointer of the next node to skip the node to be deleted
    }

    free(temp); // Free the memory of the deleted node
}

void delete_before() {
    int n;

    if(head == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter the element whose immediate before element you want to delete: ");
    scanf("%d", &n);

    struct node *temp = head;
    while(temp != NULL && temp->data != n) { // Traverse until reaching the specified element
        temp = temp->next;
    }

    if(temp == NULL) { // If specified element is not found
        printf("Element %d not found in the list", n);
        return;
    }

    if(temp->prev == NULL) { // If there is no element before the first element
        printf("There is no element before the first element.");
        return;
    }

    struct node *deleteNode = temp->prev; // Node to be deleted is the one before the specified element
    if(deleteNode->prev == NULL) { // If the node to be deleted is the head node
        head = temp; // Update head to point to the specified element
    } else {
        temp->prev = deleteNode->prev; // Update the prev pointer of the specified element to skip the node to be deleted
        deleteNode->prev->next = temp; // Update the next pointer of the previous node to skip the node to be deleted
    }

    free(deleteNode); // Free the memory of the deleted node
}

void delete_after() {
    int n;

    if(head == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter the element whose immediate after element you want to delete: ");
    scanf("%d", &n);

    struct node *temp = head;
    while(temp != NULL && temp->data != n) { // Traverse until reaching the specified element
        temp = temp->next;
    }

    if(temp == NULL) { // If specified element is not found
        printf("Element %d not found in the list", n);
        return;
    }

    if(temp->next == NULL) { // If there is no element after the last element
        printf("There is no element after the last element.");
        return;
    }

    struct node *deleteNode = temp->next; // Node to be deleted is the one after the specified element
    temp->next = deleteNode->next; // Update the next pointer of the specified element to skip the node to be deleted

    if(deleteNode->next != NULL) { // If the node to be deleted is not the last node
        deleteNode->next->prev = temp; // Update the prev pointer of the next node to skip the node to be deleted
    }

    free(deleteNode); // Free the memory of the deleted node
}

