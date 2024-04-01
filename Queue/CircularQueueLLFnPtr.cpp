#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void initializeQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return (q->front == NULL);
}

void enqueue(struct Queue *q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = q->front; // For a circular queue, rear's next will always point to front

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data;
    struct Node* temp = q->front;
    data = temp->data;

    if (q->front == q->rear) { // Only one element in the queue
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
    return data;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);
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
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1)
                    printf("Dequeued element: %d\n", data);
                break;
            case 3:
                display(&q);
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

