#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newNode(int data) {
    struct StackNode* stackNode =
        (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to push an item to the stack
void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop an item from the stack
int pop(struct StackNode** root) {
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to evaluate a prefix expression
void evaluatePrefix(char* expr) {
    struct StackNode* operands = NULL;

    // Process the expression from right to left
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // If the character is an operand, convert it to integer and push it onto the stack
        if (isdigit(ch)) {
            push(&operands, ch - '0');
        } else if (ch == ' ') {
            // Ignore spaces
            continue;
        } else {
            // If the character is an operator, pop two operands from the stack,
            // perform the operation, and push the result back onto the stack
            int op1 = pop(&operands);
            int op2 = pop(&operands);

            switch (ch) {
                case '+':
                    push(&operands, op1 + op2);
                    break;
                case '-':
                    push(&operands, op1 - op2);
                    break;
                case '*':
                    push(&operands, op1 * op2);
                    break;
                case '/':
                    push(&operands, op1 / op2);
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return;
            }
        }
    }

    // The final result is the top element of the stack
    printf("Result: %d\n", pop(&operands));
}

int main() {
    char prefixExpr[100];
    printf("Enter a prefix expression: ");
    scanf("%s", prefixExpr); // Use scanf instead of fgets

    // Evaluate the prefix expression
    evaluatePrefix(prefixExpr);

    return 0;
}
