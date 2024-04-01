#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue q;

void initializeQueue() {
    q.front = q.rear = NULL;
}

int isEmpty() {
    return (q.front == NULL);
}

void enqueue() {
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = q.front;

    if (isEmpty()) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    int data;
    struct Node* temp = q.front;
    data = temp->data;

    if (q.front == q.rear) {
        q.front = q.rear = NULL;
    } else {
        q.front = q.front->next;
        q.rear->next = q.front;
    }

    free(temp);
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q.front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q.front);
    printf("\n");
}

int main() {
    initializeQueue();
    int choice, data;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                data = dequeue();
                if (data != -1)
                    printf("Dequeued element: %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

