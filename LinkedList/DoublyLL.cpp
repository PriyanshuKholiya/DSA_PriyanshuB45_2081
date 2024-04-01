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

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = NULL;
    head = newnode;

    printf("\nDo you want to continue (y/n): ");
    scanf(" %c", &ch);

    while(ch == 'y' || ch == 'Y') {
        printf("\nEnter next element: ");
        scanf("%d", &n);

        struct node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = n;
        newnode->prev = temp;
        newnode->next = NULL;
        temp->next = newnode;

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);
    }
}

void display() {
    if(head == NULL)
        printf("List is empty");
    else {
        struct node *temp = head;

        printf("Doubly Linked List: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void insert_beg() {
    int n;
    printf("\nEnter element to insert at the beginning: ");
    scanf("%d", &n);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;
    
    head = newnode;
}

void insert_end() {
    int n;
    printf("\nEnter element to insert at the end: ");
    scanf("%d", &n);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
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

    struct node *temp = head;
    while(i < pos-1 && temp->next != NULL) { 
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL) {
        printf("Position out of range");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
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
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    struct node *temp = head;
    while(temp != NULL && temp->data != elebef) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Element %d not found in the list", elebef);
        return;
    }
    
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
	
    if (head == NULL) {
        printf("List is empty");
        return;
    }
	
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &n);
	
    printf("Enter the element after which you want to insert: ");
    scanf("%d", &eleaft);
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    struct node *temp = head;
    while(temp != NULL && temp->data != eleaft) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Element %d not found in the list", eleaft);
        return;
    }
    
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
    if(head == NULL) {
        printf("List is empty");
        return;
    }
	
    struct node *temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

void delete_end() {
    if(head == NULL) {
        printf("List is empty");
        return;
    }
	
    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    if(temp->prev == NULL) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }

    free(temp);
}

void delete_patloc() {
    int pos, i = 1;

    if(head == NULL) {
        printf("List is empty");
        return;
    }
	
    printf("\nEnter the position of element to be deleted: ");
    scanf("%d", &pos);

    struct node *temp = head;
    while(i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if(temp == NULL) {
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

