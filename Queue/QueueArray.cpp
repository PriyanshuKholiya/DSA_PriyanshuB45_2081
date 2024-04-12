#include<stdio.h>
#define MAXSIZE 10

int queue[MAXSIZE],front=0,rear=-1;//rear behind front

void Insert();
void Delete();
void Display();

int main() {
    int choice;
    do {
        printf("\n----Stack Operations Menu----\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	Insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
        }
    } while (choice != 4);
    return 0;
}

void Insert(){
	int n;
	if(rear==MAXSIZE-1)//when inserter reaches max-1/overflow
	printf("Queue is full");
	else
	{ printf("Enter the element you want to insert ");//input element
	scanf("%d",&n);
	rear++;//increase rear towards front by one step
	queue[rear]=n;//store input in the rear index
	}
	}
	
void Delete(){
	if(front>rear)//when rear is behind front or front is ahead of rear
	printf("queue is empty");
	else
	{int n;//store the element to be deleted in n
	n=queue[front];
	front++;//increase front forward by a step
	printf("The deleted elememt is %d",n);//display whats deleted //suppose front=0 rear=0 hence one element is there if front++->front=1 rear gets left behind and there is nothing to print from front to rear by incrementing front 
	// Check if queue becomes empty after deletion
        if (front > rear) {
            // If queue becomes empty, reset front and rear indices
            front = 0;
            rear = -1;
        }
	}
}

void Display() {
    if (front > rear)//when rear is behind front 
        printf("Queue is empty");
    else {
        printf("\nThe elements of the queue are:");
        for (int i = front; i <= rear; i++)//displays elements from front to rear in backwards fashion
            printf("\n%d", queue[i]);
    }
}


