#include <stdio.h>
#include <stdlib.h>//to add malloc and similar functions


struct node {
    int data;
    struct node *prev;//to point to previous node
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

// Main function
int main() {
    int choice;
    
    // Menu-driven loop
    do {
        printf("\n ----------------Doubly Linked List Menu----------------");
        printf("\n 1. Create");
        printf("\n 2. Display");

        printf("\n\n Insertion options:");
        printf("\n 3. Insert element at beginning");
        printf("\n 4. Insert element at the end");
        printf("\n 5. Insert element at a particular location");
        printf("\n 6. Insert element before a specific element");
        printf("\n 7. Insert element after a specific element");

        printf("\n\n Deletion options:");
        printf("\n 8. Delete element at the beginning");
        printf("\n 9. Delete element at the end");
        printf("\n 10. Delete element at a particular location");
        printf("\n 11. Delete element before a specific element");
        printf("\n 12. Delete element after a specific element");

        printf("\n 13. Exit");
        printf("\n\n ---------------------------------------------------------");

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

    struct node *newnode = (struct node*)malloc(sizeof(struct node));// Create a new node for the first element
    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = NULL;
    head = newnode;

    printf("\nDo you want to continue (y/n): ");// Ask user if they want to continue adding more elements
    scanf(" %c", &ch);

    while(ch == 'y' || ch == 'Y') {// till ch equals y or Y run through the loop
        printf("\nEnter next element: ");
        scanf("%d", &n);

        struct node *temp = head;
        while(temp->next != NULL) {// iterate till next of temp encounters null ie last node
            temp = temp->next;
        }
	    
        newnode = (struct node*)malloc(sizeof(struct node));// Create a new node for the next element
        newnode->data = n;
        newnode->prev = temp;//points to temp that was the previous or last element
        newnode->next = NULL;
        temp->next = newnode;//fixes newnode to the next of temp that was the previous node

        printf("\nDo you want to continue (y/n): ");// Ask user if they want to continue adding more elements if ch equals y or Y then continue
        scanf(" %c", &ch);
    }
}

void display() {
    if(head == NULL)//if head is null hence the list is empty
        printf("List is empty");
    else {
        struct node *temp = head;

        printf("Doubly Linked List: ");
        while(temp != NULL) {//else print till temp that points to head moves forward and surpasses the last element and prints its value
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void insert_beg() {
    int n;
    printf("\nEnter element to insert at the beginning: ");
    scanf("%d", &n);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));// Create a new node for the element
    newnode->data = n;
    newnode->prev = NULL;//the new head won't have any elements before it
    newnode->next = head;//points to the current head in next since its going to take its place as head making it the second element

    if(head != NULL)// if head is not null ie it exists then update its prev to point to newnode
        head->prev = newnode;
    
    head = newnode;
}

void insert_end() {
    int n;
    printf("\nEnter element to insert at the end: ");
    scanf("%d", &n);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));// Create a new node for the element
    newnode->data = n;
    newnode->next = NULL;

    struct node *temp = head;
    while(temp->next != NULL) {//traverse forward next of temp from head till it encounters the last element whose next is null 
        temp = temp->next;
    }
	
    temp->next = newnode;// Update pointers to insert the new node at the end
    newnode->prev = temp;
}

void insert_patloc() {
    int n, pos, i = 1;
	
    if (head == NULL) {//if head doesn't point to anything list is empty
        printf("List is empty");
        return;
    }
	
    printf("\nEnter element to insert: ");//input element to insert
    scanf("%d", &n);
	
    printf("Enter position at which the node is to be inserted: ");//input position at which it is to be inserted
    scanf("%d", &pos);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));// Create a new node for the element
    newnode->data = n;

    struct node *temp = head;
    while(i < pos && temp->next != NULL) { //stop the loop when i starts from 1 and reaches one number behind the given position so it can add the element at that position
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL) { // if the position points to null means it is an invalid position and our pointer had moved out of range 
        printf("Position out of range");
        return;
    }

    // Update pointers to insert the new node at the specified position
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void insert_before() {
    int n, elebef;
	
    if (head == NULL) {//if head points to nothing ie list is empty 
        printf("List is empty");
        return;
    }
	
    printf("\nEnter the element you want to insert: ");//input element to insert
    scanf("%d", &n);
	
    printf("Enter the element before which you want to insert: ");//input element before which the user wants to place the element
    scanf("%d", &elebef);
    
    // Create a new node for the element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    struct node *temp = head;
    while(temp != NULL && temp->data != elebef) { // Traverse to the specific element
        temp = temp->next;
    }
   
    if(temp == NULL) {//if tmp doesnt encounter elebef it continues to move till it encounters null and gets out of range hence we check if it had encountered null
        printf("Element %d not found in the list", elebef);
        return;
    }
    
    // Update pointers to insert the new node before the specified element
    if(temp->prev == NULL) {
        newnode->next = temp;
        newnode->prev = NULL;
        temp->prev = newnode;
        head = newnode;
    } else {
        newnode->next = temp;
        newnode->prev = temp->prev;
        temp->prev->next = newnode;
        temp->prev = newnode;
    }
}

void insert_after() {
    int n, eleaft;
	
    if (head == NULL) {//if head points to nothing ie list is empty
        printf("List is empty");
        return;
    }
	
    printf("\nEnter the element you want to insert: ");//input element to insert
    scanf("%d", &n);
	
    printf("Enter the element after which you want to insert: ");//input element after which the user wants to place the element
    scanf("%d", &eleaft);
    
    // Create a new node for the element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    // Traverse to the specific element
    struct node *temp = head;
    while(temp != NULL && temp->data != eleaft) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Element %d not found in the list", eleaft);//if tmp doesnt encounter eleaft it continues to move till it encounters null and gets out of range hence we check if it had encountered null
        return;
    }
    
    // Update pointers to insert the new node after the specified element
    if(temp->next == NULL) {
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    } else {
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void delete_beg() {
    if(head == NULL) {// if head is null list is empty
        printf("List is empty");
        return;
    }
	
    struct node *temp = head;//create a pointer temp which points to head
    head = head->next;//move head forward
    if(head != NULL)//check if the forward node wasn't empty
        head->prev = NULL;//put null in its prev pointer

    free(temp);
}

void delete_end() {
    if(head == NULL) {//if head is null list is empty
        printf("List is empty");
        return;//return from fnc 
    }
	
    struct node *temp = head;//else assign head to temp
    while(temp->next != NULL) {//move temp till it encounters the last element whose next is null
        temp = temp->next;
    }

    if(temp->prev == NULL) {//it the list has only one element
    head = NULL;
  } else {
    temp->prev->next = NULL;//update the previous node's next to null and it becomes the last node
    temp->prev = NULL; // Set the prev pointer of the deleted node to NULL
  }


    free(temp);
}

void delete_patloc() {
    int pos, i = 1;

    if(head == NULL) {//if head is null list is empty 
        printf("List is empty");
        return;
    }
	
    printf("\nEnter the position of element to be deleted: ");//input position at which element is to be deleted
    scanf("%d", &pos);

    struct node *temp = head;
    while(i < pos && temp != NULL) {//iterate till temp reaches the node before position or else it encounters null
        temp = temp->next;
        i++;
    }

    if(temp == NULL) {//if it encounters null means the position was not available in the list hence the pointer went out of range
        printf("Position out of range");
        return;
    }

    if(temp->prev == NULL) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to delete the element before a specific element in the doubly linked list
void delete_before() {
    int n;

    if(head == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter the element whose immediate before element you want to delete: ");
    scanf("%d", &n);

    struct node *temp = head;
    while(temp != NULL && temp->data != n) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Element %d not found in the list", n);
        return;
    }

    if(temp->prev == NULL) {
        printf("There is no element before the first element.");
        return;
    }

    struct node *deleteNode = temp->prev;
    if(deleteNode->prev == NULL) {
        head = temp;
    } else {
        temp->prev = deleteNode->prev;
        deleteNode->prev->next = temp;
    }

    free(deleteNode);
}

// Function to delete the element after a specific element in the doubly linked list
void delete_after() {
    int n;

    if(head == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter the element whose immediate after element you want to delete: ");
    scanf("%d", &n);

    struct node *temp = head;
    while(temp != NULL && temp->data != n) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Element %d not found in the list", n);
        return;
    }

    if(temp->next == NULL) {
        printf("There is no element after the last element.");
        return;
    }

    struct node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    if(deleteNode->next != NULL) {
        deleteNode->next->prev = temp;
    }

    free(deleteNode);
}
