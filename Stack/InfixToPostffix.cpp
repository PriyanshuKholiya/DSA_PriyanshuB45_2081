#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for stack
struct Stack {
    int top;
    unsigned capacity;
    char *array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

// Function to return the top element of the stack
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to check precedence of operators
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

// Function to convert infix expression to postfix expression
char* infixToPostfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if(!stack)
        return NULL;
    char *postfix = (char *)malloc(strlen(exp) * sizeof(char));
    for (i = 0, k = -1; exp[i]; ++i) {
        // If the scanned character is an operand, add it to the output
        if (isOperand(exp[i]))
            postfix[++k] = exp[i];
        // If the scanned character is an '(', push it to the stack
        else if (exp[i] == '(')
            push(stack, exp[i]);
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL; // Invalid expression
            else
                pop(stack);
        } else { // Operator encountered
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    // Pop all the remaining operators from the stack
    while (!isEmpty(stack))
        postfix[++k] = pop(stack);
    postfix[++k] = '\0';
    return postfix;
}

// Main function
int main() {
    char exp[100];
    printf("Enter infix expression: ");
    fgets(exp, sizeof(exp), stdin);
    char *postfix = infixToPostfix(exp);
    if(postfix)
        printf("Postfix expression: %s\n", postfix);
    else
        printf("Invalid infix expression\n");
    return 0;
}
