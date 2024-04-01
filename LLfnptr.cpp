#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void create(struct node **start);
void display(struct node *start);
void insert_beg(struct node **start, int data);
void insert_end(struct node **start, int data);
void insert_patloc(struct node **start, int data, int pos);
void insert_before(struct node **start, int data, int elebef);
void insert_after(struct node **start, int data, int eleaft);
void delete_beg(struct node **start);
void delete_end(struct node **start);
void delete_patloc(struct node **start, int pos);
void delete_before(struct node **start, int elebef);
void delete_after(struct node **start, int eleaft);

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
            case 1: create(&start); break;
            case 2: display(start); break;
            case 3: {
                int data;
                printf("\nEnter element to insert at the beginning: ");
                scanf("%d", &data);
                insert_beg(&start, data);
                break;
            }
            case 4: {
                int data;
                printf("\nEnter element to insert at the end: ");
                scanf("%d", &data);
                insert_end(&start, data);
                break;
            }
            case 5: {
                int data, pos;
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                printf("Enter position at which the node is to be inserted: ");
                scanf("%d", &pos);
                insert_patloc(&start, data, pos);
                break;
            }
            case 6: {
                int data, elebef;
                printf("\nEnter the element you want to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which you want to insert: ");
                scanf("%d", &elebef);
                insert_before(&start, data, elebef);
                break;
            }
            case 7: {
                int data, eleaft;
                printf("\nEnter the element you want to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which you want to insert: ");
                scanf("%d", &eleaft);
                insert_after(&start, data, eleaft);
                break;
            }
            case 8: delete_beg(&start); break;
            case 9: delete_end(&start); break;
            case 10: {
                int pos;
                printf("\nEnter the position of element to be deleted: ");
                scanf("%d", &pos);
                delete_patloc(&start, pos);
                break;
            }
            case 11: {
                int elebef;
                printf("\nEnter the element whose immediate before element you want to delete: ");
                scanf("%d", &elebef);
                delete_before(&start, elebef);
                break;
            }
            case 12: {
                int eleaft;
                printf("\nEnter the element whose immediate after element you want to delete: ");
                scanf("%d", &eleaft);
                delete_after(&start, eleaft);
                break;
            }
        }
    } while (choice != 13);

    return 0;
}

void create(struct node **start) {
    int n;
    char ch;
    struct node *newnode, *temp;

    printf("\nEnter first element: ");
    scanf("%d", &n);
    *start = (struct node *)malloc(sizeof(struct node));
    (*start)->data = n;
    (*start)->next = NULL;

    do {
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y') {
            printf("\nEnter next element: ");
            scanf("%d", &n);
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = n;
            newnode->next = NULL;
            temp = *start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    } while (ch == 'y' || ch == 'Y');
}

void display(struct node *start) {
    struct node *temp;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = start;
    while (temp != NULL) {
        printf("\n%d ", temp->data);
        temp = temp->next;
    }
}

void insert_beg(struct node **start, int data) {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *start;
    *start = newnode;
}

void insert_end(struct node **start, int data) {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    temp = *start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_patloc(struct node **start, int data, int pos) {
    int i = 1;
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (pos <= 1) {
        newnode->next = *start;
        *start = newnode;
        return;
    }
    temp = *start;
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

void insert_before(struct node **start, int data, int elebef) {
    struct node *newnode, *temp, *prev;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *start;
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
        newnode->next = *start;
        *start = newnode;
    } else {
        newnode->next = temp;
        prev->next = newnode;
    }
}

void insert_after(struct node **start, int data, int eleaft) {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *start;
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

void delete_beg(struct node **start) {
    struct node *temp;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *start;
    *start = (*start)->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

void delete_end(struct node **start) {
    struct node *temp, *prev;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *start;
    prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        printf("Deleted element is %d\n", (*start)->data);
        free(*start);
        *start = NULL;
    } else {
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        prev->next = NULL;
    }
}

void delete_patloc(struct node **start, int pos) {
    int i = 1;
    struct node *temp, *prev;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *start;
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
        *start = (*start)->next;
        printf("The deleted element is %d\n", temp->data);
        free(temp);
    } else {
        prev->next = temp->next;
        printf("The deleted element is %d\n", temp->data);
        free(temp);
    }
}

void delete_before(struct node **start, int elebef) {
    struct node *temp, *prev, *prevPrev;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *start;
    prevPrev = NULL;
    prev = NULL;
    while (temp != NULL && temp->data != elebef) {
        prevPrev = prev;
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || prev == NULL) {
        printf("Element not found or no element before it\n");
        return;
    }

    if (prevPrev == NULL) {
        *start = (*start)->next;
        free(prev);
    } else {
        prevPrev->next = temp;
        free(prev);
    }
}

void delete_after(struct node **start, int eleaft) {
    struct node *temp, *prev;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *start;
    prev = NULL;
    while (temp != NULL && temp->data != eleaft) {
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

