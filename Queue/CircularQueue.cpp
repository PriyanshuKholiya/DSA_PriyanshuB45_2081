#include<stdio.h>
#define MAXSIZE 10
int cqueue[MAXSIZE], rear = -1, front = -1; // Circular queue and its front and rear indices

void insert();
void delete1();
void display();

int main() {
    int choice;
    do {
        printf("\n-------------CIRCULAR QUEUE MENU------------");
        printf("\n1.Insert\n2.Delete\n3.Display \n4.Exit");
        printf("\n------------------------------");
        printf("\nEnter Your Choice ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete1();
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 4); 
    return 0;
}

void insert() {
    int n;
    // Check if queue is full
    if ((rear + 1) % MAXSIZE == front)
        printf("\nQueue is full");
    else {
        printf("\nEnter an element: ");
        scanf("%d", &n);
        if (rear == -1 && front == -1) { // If queue is initially empty, set front and rear to 0
            rear = 0;
            front = 0;
        } else {
            rear = (rear + 1) % MAXSIZE;// Increment rear circularly
        }
        cqueue[rear] = n;// Insert element at rear position
    }
}

void delete1() {
    int n;
    if (rear == -1 && front == -1) // Check if queue is empty
        printf("\nQueue is empty");
    else {
        n = cqueue[front];// store the element to be deleted
        printf("\nDeleted element is %d", n);
        
        if (front == rear) {// If queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAXSIZE;// Increment front circularly
        }
    }
}

void display() {
    if (rear == -1 && front == -1)// empty queue 
        printf("\nQueue is empty");
    else
        printf("\nElements of Queue");
    for (int i = front; i != rear; (i = (i + 1) % MAXSIZE)) {// Iterate through the queue circularly and display elements
        printf("%d\t", cqueue[i]);
    }
    printf("%d\t", cqueue[rear]);  // Display last element
}
