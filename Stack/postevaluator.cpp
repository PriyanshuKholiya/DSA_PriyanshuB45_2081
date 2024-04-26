#include <stdio.h>
#include <stdlib.h> 

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1; // Initialize top to -1 to indicate an empty stack
}

// Function to push an element onto the stack
void push(Stack *s, int item) {
    if (s->top == MAX_SIZE - 1) { // Check for stack overflow
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++(s->top)] = item; // Increment top and add the item to the stack
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (s->top == -1) { // Check for stack underflow
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[(s->top)--]; // Decrement top and return the popped item
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char *expression) {
    Stack stack;
    initialize(&stack); // Initialize the stack

    int i = 0;
    while (expression[i] != '\0') { // Iterate through each character in the expression
        if (expression[i] >= '0' && expression[i] <= '9') { // Check if the character is a digit
            push(&stack, expression[i] - '0'); // Convert the character digit to an integer and push onto the stack
        } else {
            // If the character is an operator
            int operand2 = pop(&stack); // Pop the top two elements from the stack
            int operand1 = pop(&stack);
            switch (expression[i]) { // Perform the operation based on the operator
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) { // Check for division by zero
                        printf("Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default: // Invalid character in expression
                    printf("Invalid character in expression\n");
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }
    return pop(&stack); // Return the final result from the stack
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin); // Read the expression from the user

    int result = evaluatePostfix(expression); // Evaluate the expression
    printf("Result: %d\n", result); // Print the result

    return 0;
}
