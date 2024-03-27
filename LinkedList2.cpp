#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL, *newnode, *temp;;

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
        printf("\n ----------------Linked List Menu----------------");
        printf("\n 1. Create");
        printf("\n 2. Display");
        printf("\n 3. Insert element at beginning");
        printf("\n 4. Insert element at the end");
        printf("\n 5. Insert element at a particular location");
        printf("\n 6. Insert element before a specific element");
        printf("\n 7. Insert element after a specific element");
        printf("\n 8. Delete element at beginning");
        printf("\n 9. Delete element at the end");
        printf("\n 10. Delete element at a particular location");
        printf("\n 11. Delete element before a specific element");
        printf("\n 12. Delete element after a specific element");
        printf("\n 13. Exit");
        printf("\n\n ------------------------------------------------");
        printf("\n Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
    } while (choice != 13);

    return 0;
}

void create() {
    int n;
    char ch;
    
    printf("\nEnter first element: ");//Assign the first element to start
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->next = NULL;
    
    do {//will follow at least once
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y') {
            printf("\nEnter next element: ");
            scanf("%d", &n);
            newnode = (struct node *)malloc(sizeof(struct node));//create a new node and link it to the prev node's next
            newnode->data = n;
            newnode->next = NULL;//define newnode's next as NULL since it will be the last element
            temp = start;
            while (temp->next != NULL) {//temp traverses to the last node from start in the current list
                temp = temp->next;
            }
            temp->next = newnode;//join the newnode to the end 
        }
    } while (ch == 'y' || ch == 'Y');
}

void display() {
    if (start == NULL) {
        printf("List is empty\n");
        return;//returns the function and prevents further execution
    }
    temp = start;
    while (temp != NULL) {//prints elements till temp passes the last node and gets assigned null which was contained in the last node's next
        printf("\n%d ", temp->data);
        temp = temp->next;
    }
}

void insert_beg() {
    int n;
    
    printf("\nEnter element to insert at the beginning: ");
    scanf("%d", &n);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = start;// create a newnode and put start in its address part
    start = newnode;//shift start to the newnode
}

void insert_end() {
    int n;
    struct node *newnode, *temp;

    printf("\nEnter element to insert at the end: ");
    scanf("%d", &n);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    temp = start;
    while (temp->next != NULL) {//move tmp till it encounters the last node ie the node whose address part is NULL
        temp = temp->next;
    }
    temp->next = newnode;//link the newnode to the address part of the last node making newnode the new lastnode
}

void insert_patloc() {
    int n, pos, i = 1;

    printf("\nEnter element to insert: ");
    scanf("%d", &n);
    printf("Enter position at which the node is to be inserted: ");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;

    if (pos <= 1) {
        newnode->next = start;
        start = newnode;
        return;
    }
    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_before() {
    int n, elebef;
    struct node *newnode, *temp, *prev;

    printf("\nEnter the element you want to insert: ");
    scanf("%d", &n);
    printf("Enter the element before which you want to insert: ");
    scanf("%d", &elebef);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    prev = NULL;
    while (temp != NULL && temp->data != elebef) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found\n", elebef);
        return;
    }

    if (prev == NULL) {
        newnode->next = start;
        start = newnode;
    } else {
        newnode->next = temp;
        prev->next = newnode;
    }
}

void insert_after() {
    int n, eleaft;
    struct node *newnode, *temp;

    printf("\nEnter the element you want to insert: ");
    scanf("%d", &n);
    printf("Enter the element after which you want to insert: ");
    scanf("%d", &eleaft);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    while (temp != NULL && temp->data != eleaft) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found\n", eleaft);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_beg() {
    struct node *temp;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    start = start->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

void delete_end() {
    struct node *temp, *prev;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        printf("Deleted element is %d\n", start->data);
        free(start);
        start = NULL;
    } else {
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        prev->next = NULL;
    }
}

void delete_patloc() {
    int pos, i = 1;
    struct node *temp, *prev;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nEnter the position of element to be deleted: ");
    scanf("%d", &pos);

    temp = start;
    prev = NULL;
    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (prev == NULL) {
        start = start->next;
        printf("The deleted element is %d\n", temp->data);
        free(temp);
    } else {
        prev->next = temp->next;
        printf("The deleted element is %d\n", temp->data);
        free(temp);
    }
}

void delete_before() {
    int n;
    struct node *temp, *prev, *prevPrev;

    printf("\nEnter the element whose immediate before element you want to delete: ");
    scanf("%d", &n);

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    prevPrev = NULL;
    prev = NULL;
    while (temp != NULL && temp->data != n) {
        prevPrev = prev;
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || prev == NULL) {
        printf("Element not found or no element before it\n");
        return;
    }

    if (prevPrev == NULL) {
        start = start->next;
        free(prev);
    } else {
        prevPrev->next = temp;
        free(prev);
    }
}

void delete_after() {
    int n;
    struct node *temp, *prev;

    printf("\nEnter the element whose immediate after element you want to delete: ");
    scanf("%d", &n);

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    prev = NULL;
    while (temp != NULL && temp->data != n) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Element not found or no element after it\n");
        return;
    }

    prev = temp->next;
    temp->next = prev->next;
    free(prev);
}

