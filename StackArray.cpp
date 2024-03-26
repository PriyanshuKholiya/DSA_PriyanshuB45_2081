#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10 
//we use a macro to define the max size of the array if we change the value of macro here, the value of macro in all other places changes automatically

int stack[MAXSIZE],top=-1;//we use top as a pointer to traverse the stack

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
	if(top==MAXSIZE-1)
	printf("Stack is full");
	else
	{ printf("Enter the element you want to push ");
	scanf("%d",&n);
	top++;//updates the top 
	stack[top]=n;
	}
	}
	
void Pop(){//it doesnt actually delete the element it just decreases the pointer by a unit 
	if(top<0)
	printf("stack is empty");
	else
	{int n;
	n=stack[top];
	top--;
	printf("The popped elememt is %d",n);
	}
}

void Display(){
	if(top<0)
	printf("stack is empty");
	else
	{printf("The elements of the stack are:");
	for(int i=top;i>=0;i--)//prints elements in a reverse order from top to bottom
	printf("\n%d",stack[i]);
	}
}

