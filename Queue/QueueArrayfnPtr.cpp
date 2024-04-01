#include<stdio.h>
#define MAXSIZE 10

void Insert(int *, int *, int []);
void Delete(int *, int *, int []);
void Display(int, int, int []);

int main() {
    int queue[MAXSIZE], front = 0, rear = -1, choice;
    do {
        printf("\n----Queue Operations Menu----\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Insert(&front, &rear, queue);
                break;
            case 2:
                Delete(&front, &rear, queue);
                break;
            case 3:
                Display(front, rear, queue);
                break;
        }
    } while (choice != 4);
    return 0;
}

void Insert(int *front, int *rear, int queue[]) {
    int n;
    if (*rear == MAXSIZE - 1)
        printf("Queue is full");
    else {
        printf("Enter the element you want to insert: ");
        scanf("%d", &n);
        (*rear)++;
        queue[*rear] = n;
    }
}

void Delete(int *front, int *rear, int queue[]) {
    if (*front > *rear)
        printf("Queue is empty");
    else {
        int n;
        n = queue[*front];
        (*front)++;
        printf("The deleted element is %d", n);
    }
}

void Display(int front, int rear, int queue[]) {
    if (front > rear)
        printf("Queue is empty");
    else {
        printf("\nThe elements of the queue are:");
        for (int i = front; i <= rear; i++)
            printf("\n%d", queue[i]);
    }
}

