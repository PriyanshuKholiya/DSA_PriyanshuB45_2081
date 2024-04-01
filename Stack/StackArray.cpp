#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10

int stack[MAXSIZE],top=-1;

void Push();
void Pop();
void Display();

int main() {
    int choice;
    do {
        printf("/n----Stack Operations Menu----\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Display();
                break;
        }
    } while (choice != 4);
    return 0;
}


void Push(){
	int n;
	if(top==MAXSIZE-1)//overflow
	printf("Stack is full");
	else
	{ printf("Enter the element you want to push ");//input the element by incrementing top by 1
	scanf("%d",&n);
	top++;
	stack[top]=n;
	}
	}
	
void Pop(){
	if(top<0)
	printf("stack is empty");//underflow
	else
	{int n;//save the element in some variable to display it and decrease top by 1
	n=stack[top];
	top--;
	printf("The popped elememt is %d",n);
	}
}

void Display(){
	if(top<0)//underflow
	printf("stack is empty");
	else
	{printf("The elements of the stack are:");//print elements from top to top=0 
	for(int i=top;i>=0;i--)
	printf("\n%d",stack[i]);
	}
}

