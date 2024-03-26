#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10

int queue[MAXSIZE],front=0,rear=-1;

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
	if(rear==MAXSIZE-1)
	printf("Queue is full");
	else
	{ printf("Enter the element you want to insert ");
	scanf("%d",&n);
	rear++;
	queue[rear]=n;
	}
	}
	
void Delete(){
	if(front>rear)
	printf("queue is empty");
	else
	{int n;
	n=queue[front];
	front++;
	printf("The deleted elememt is %d",n);
	}
}

void Display(){
	if(front>rear)
	printf("Queue is empty");
	else
	{printf("\nThe elements of the stack are:");
	for(int i=rear;i>=front;i--)
	printf("\n%d",queue[i]);
	}
}


