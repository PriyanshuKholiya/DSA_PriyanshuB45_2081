#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

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
        printf("\n ----------------Circular Linked List Menu----------------");
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
        printf("\n\n ----------------------------------------------------------");

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
    newnode->next = start;
    start = newnode;

    printf("\nDo you want to continue (y/n): ");
    scanf(" %c", &ch);

    while(ch == 'y' || ch == 'Y') {
        printf("\nEnter next element: ");
        scanf("%d", &n);

        struct node *temp = start;
        while(temp->next != start) {
            temp = temp->next;
        }

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = n;
        newnode->next = start;
        temp->next = newnode;

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);
    }
}

void display() {
    if(start == NULL)
        printf("List is empty");
    else {
        struct node *temp = start;

        printf("Circular Linked List: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != start);
    }
}

void insert_beg() {
    int n;
    printf("\nEnter element to insert at the beginning: ");
    scanf("%d", &n);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;

    struct node *temp = start;
    while(temp->next != start) {
        temp = temp->next;
    }

    newnode->next = start;
    temp->next = newnode;
    start = newnode;
}

void insert_end() {
    int n;
    printf("\nEnter element to insert at the end: ");
    scanf("%d", &n);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;

    struct node *temp = start;
    while(temp->next != start) {
        temp = temp->next;
    }

    newnode->next = start;
    temp->next = newnode;
}

void insert_patloc() {
    int n, pos, i = 1;
	
    if (start == NULL) {
        printf("List not found");
        return;
    }
	
    printf("\nEnter element to insert: ");
    scanf("%d", &n);
	
    printf("Enter position at which the node is to be inserted: ");
    scanf("%d", &pos);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;

    struct node *ftmp = start;
    while(i < pos-1 && ftmp->next != start) { 
        ftmp = ftmp->next;
        i++;
    }

    newnode->next = ftmp->next;
    ftmp->next = newnode;
}

void insert_before() {
    int n, elebef;
	
    if (start == NULL) {
        printf("List not found");
        return;
    }
	
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &n);
	
    printf("Enter the element before which you want to insert: ");
    scanf("%d", &elebef);
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    struct node *ptmp = NULL;
    struct node *tmp = start;
    
    while(tmp->next != start && tmp->data != elebef) {
        ptmp = tmp;
        tmp = tmp->next;
    }
    
    if (tmp->data != elebef) {
        printf("Element %d not found in the list", elebef);
        return;
    }
    
    if (ptmp == NULL) {
        newnode->next = start;
        start = newnode;
    } else {
        ptmp->next = newnode;
        newnode->next = tmp;
    }
}

void insert_after() {
    int n, eleaft;
	
    if (start == NULL) {
        printf("List not found");
        return;
    }
	
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &n);
	
    printf("Enter the element after which you want to insert: ");
    scanf("%d", &eleaft);
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
    struct node *tmp = start;
    struct node *ptmp = NULL;
    
    while(tmp->next != start && tmp->data != eleaft) {
        ptmp = tmp;
        tmp = tmp->next;
    }
    
    if (tmp->data != eleaft) {
        printf("Element %d not found in the list", eleaft);
        return;
    }
    
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void delete_beg() {
    if(start == NULL) {
        printf("List is empty");
        return;
    }
	
    struct node *temp = start;
    struct node *last = start;

    while(last->next != start) {
        last = last->next;
    }

    start = start->next;
    last->next = start;

    free(temp);
}

void delete_end() {
    if(start == NULL) {
        printf("List is empty");
        return;
    }
	
    struct node *temp = start;
    struct node *prev = NULL;

    while(temp->next != start) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = start;
    free(temp);
}

void delete_patloc() {
    int pos, i = 1;

    if(start == NULL) {
        printf("List is empty");
        return;
    }
	
    printf("\nEnter the position of element to be deleted: ");
    scanf("%d", &pos);

    struct node *ptmp = NULL;
    struct node *tmp = start;

    while(i < pos) {
        ptmp = tmp;
        tmp = tmp->next;
        i++;
    }

    ptmp->next = tmp->next;
    free(tmp);
}

void delete_before() {
    int n;

    printf("\nEnter the element whose immediate before element you want to delete: ");
    scanf("%d", &n);

    if (start == NULL) {
        printf("List is empty");
        return;
    }

    struct node *tmp = start->next;
    struct node *ptmp = start;
    struct node *ftmp = NULL;

    while (tmp != NULL && tmp->data != n) {
        ftmp = ptmp;
        ptmp = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("Element %d not found in the list", n);
        return;
    }
    
    if (ptmp == start) {
        start = start->next;
        free(ptmp);
    } else {
        ftmp->next = tmp;
        free(ptmp);
    }
}


void delete_after() {
    int n;

    if (start == NULL) {
        printf("List is empty");
        return;
    }

    printf("\nEnter the element whose immediate after element you want to delete: ");
    scanf("%d", &n);

    struct node *tmp = start;
    struct node *ptmp = NULL;

    while (tmp != NULL && tmp->data != n) {
        ptmp = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL || tmp->next == NULL) {
        printf("Element %d not found or it is the last element in the list.", n);
        return;
    }
    
    ptmp = tmp;
    tmp = tmp->next;
    struct node *ftmp = tmp->next;
    ptmp->next = ftmp;

    printf("Deleted element after %d is %d\n", n, tmp->data);
    free(tmp);
}

