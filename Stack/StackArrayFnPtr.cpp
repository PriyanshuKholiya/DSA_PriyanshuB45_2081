#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

void Push(int *stack, int *top);
void Pop(int *stack, int *top);
void Display(int *stack, int top);

int main() {
    int stack[MAXSIZE];
    int top = -1;
    int choice;
    do {
        printf("\n----Stack Operations Menu----\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Push(stack, &top);
                break;
            case 2:
                Pop(stack, &top);
                break;
            case 3:
                Display(stack, top);
                break;
        }
    } while (choice != 4);
    return 0;
}

void Push(int *stack, int *top) {
    int n;
    if (*top == MAXSIZE - 1)
        printf("Stack is full\n");
    else {
        printf("Enter the element you want to push: ");
        scanf("%d", &n);
        (*top)++;
        stack[*top] = n;
    }
}

void Pop(int *stack, int *top) {
    if (*top < 0)
        printf("Stack is empty\n");
    else {
        int n = stack[*top];
        (*top)--;
        printf("The popped element is %d\n", n);
    }
}

void Display(int *stack, int top) {
    if (top < 0)
        printf("Stack is empty\n");
    else {
        printf("The elements of the stack are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

