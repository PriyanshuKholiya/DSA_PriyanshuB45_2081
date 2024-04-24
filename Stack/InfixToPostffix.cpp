#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Define a stack 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];//return the top element of the stack
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // Return 1 if the stack is empty
    }
    else
    {
        return 0; // Return 0 if the stack is not empty
    }
}
 

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // Return 1 if the stack is full
    }
    else
    {
        return 0; // Return 0 if the stack is not full
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val); // Print an error message if the stack is full
    }
    else{
        ptr->top++; // increment the top index of the stack
        ptr->arr[ptr->top] = val; // assign the value to the top of the stack
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n"); // error message if the stack is empty
        return -1; // Return -1 to indicate underflow
    }
    else{
        char val = ptr->arr[ptr->top]; // get the value from the top of the stack
        ptr->top--; // decrement the top index of the stack
        return val; // return the popped value
    }
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3; // return precedence 3 for '*' and '/'
    else if(ch == '+' || ch=='-')
        return 2; // return precedence 2 for '+' and '-'
    else
        return 0; // return 0 for other characters (operands)
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1; // return 1 if the character is an operator
    else
        return 0; // return 0 if the character is not an operator
}

char* infixToPostfix(char* infix){
    // create a stack to store operators
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; // set the size of the stack
    sp->top = -1; // initialize the top index of the stack
    sp->arr = (char *) malloc(sp->size * sizeof(char)); // allocate memory for the stack
    
    // allocate memory for the postfix expression
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // track infix traversal
    int j = 0; // track postfix addition 
    
    // Process the infix expression
    while (infix[i]!='\0')
    {
        // If the current character is not an operator, add it to the postfix expression
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        // if the current character is an operator
        else{
            // if the precedence of the current operator is higher than the top operator in the stack, push it onto the stack
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            // if the precedence of the current operator is lower than or equal to the top operator in the stack
            else{
                // pop operators from the stack and add them to the postfix expression until a lower precedence operator is encountered
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    
    // pop any remaining operators from the stack and add them to the postfix expression
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    
    postfix[j] = '\0'; // add null character to mark the end of the postfix expression
    return postfix; // return the postfix expression
}

int main()
{
    // Input infix expression
    char * infix = "x-y/z-k*d";
    // Convert infix expression to postfix expression and print the result
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
