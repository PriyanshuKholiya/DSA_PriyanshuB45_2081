#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is full
bool isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = c;
}

// Function to pop an item from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to check if parenthesis are balanced
bool isBalanced(char *exp) {
    struct Stack s;
    initialize(&s);
    char c;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmpty(&s)) {
                return false;
            } else {
                c = pop(&s);
                if ((exp[i] == ')' && c != '(') ||
                    (exp[i] == ']' && c != '[') ||
                    (exp[i] == '}' && c != '{')) {
                    return false;
                }
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char exp[MAX_SIZE];

    printf("Enter expression: ");
    fgets(exp, MAX_SIZE, stdin);

    if (isBalanced(exp)) {
        printf("Parentheses are balanced\n");
    } else {
        printf("Parentheses are not balanced\n");
    }

    return 0;
}
