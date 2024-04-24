#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int isEmpty(struct stack *ptr)
{
    // If the top of the stack is -1, indicating no elements are present, return 1 (true)
    if (ptr->top == -1)
    {
        return 1; // Stack is empty
    }
    else
    {
        return 0; // Stack is not empty
    }
}

int isFull(struct stack *ptr)
{
    // If the top of the stack is equal to (size - 1), it means the stack is full
    if (ptr->top == ptr->size - 1)
    {
        return 1; // Return 1 to indicate that the stack is full
    }
    else
    {
        return 0; // Return 0 to indicate that the stack is not full
    }
}

void push(struct stack* ptr, char val){
    // Check if the stack is full
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val); // Print an error message if the stack is full
    }
    else{
        ptr->top++; // Increment the top index of the stack
        ptr->arr[ptr->top] = val; // Assign the value to the top of the stack
    }
}
 
char pop(struct stack* ptr){
    // Check if the stack is empty
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n"); // Print an error message if the stack is empty
        return -1; // Return -1 to indicate underflow
    }
    else{
        char val = ptr->arr[ptr->top]; // Get the value from the top of the stack
        ptr->top--; // Decrement the top index of the stack
        return val; // Return the popped value
    }
}

char stackTop(struct stack* sp){
    return sp->arr[sp->top]; // Return the element at the top of the stack
}

int match(char a, char b){
    // Check if the parenthesis characters 'a' and 'b' form a matching pair
    if(a=='{' && b=='}'){
        return 1; // Return 1 if '{' matches with '}'
    }
    if(a=='(' && b==')'){
        return 1; // Return 1 if '(' matches with ')'
    }
    if(a=='[' && b==']'){
        return 1; // Return 1 if '[' matches with ']'
    }
    return 0;  // If no match, return 0
}

int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char)); // Allocate memory for the stack
    
    char popped_ch;
 
    // Iterate through the expression
    for (int i = 0; exp[i]!='\0'; i++)
    {
        // If current character is an opening parenthesis, push it onto the stack
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        // If current character is a closing parenthesis
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            // If the stack is empty, return 0 indicating imbalance
            if(isEmpty(sp)){
                return 0;
            }
            // Otherwise, pop from the stack and check if the popped character matches the current closing parenthesis
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){
                return 0;  // If there's no match, return 0 indicating imbalance
            }
        }
    }
 
    // After iterating through the expression, if the stack is empty, return 1 indicating balance, else return 0
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
 
int main()
{
    // Test expression
    char * exp = "[4-6]((8){(9-8)})";
   
    if(parenthesisMatch(exp)){// Call the parenthesisMatch function to check if parentheses are balanced
        printf("The parenthesis is balanced");
    }
    else{
        printf("The parenthesis is not balanced");
    }
    return 0;
}
