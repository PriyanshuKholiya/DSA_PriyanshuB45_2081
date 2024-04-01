#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* create();
void display(struct node *);
struct node* push(struct node *);
struct node* pop(struct node *);

int main(){
    struct node *start = NULL;
	int choice;
	do{
	    printf("\n---Stack operation menu---");
	    printf("\n1.Create\n2.Push\n3.Pop\n4.Display\n5.Exit");
	    printf("\n----------------------------");
	    printf("\nEnter your choice: ");
	    scanf("%d",&choice);
	
	    switch(choice){
		    case 1:
		        start = create();
		        break;
		    case 2:
		        start = push(start);
		        break;
		    case 3:
		        start = pop(start);
		        break;
		    case 4:
		        display(start);
		        break;
	    }
	}while(choice!=5);
	return 0;	
}

struct node* create(){
    int n;
    char ch;
    printf("Enter an element: ");
    scanf("%d", &n);
    struct node *start = (struct node*)(malloc(sizeof(struct node)));
    start->data = n;
    start->next = NULL;
    struct node *tmp = start;
    printf("Do you want to continue? (y/n): ");
    ch = getche();
    while(ch == 'y' || ch == 'Y'){
        printf("\nEnter an element: ");
        scanf("%d", &n);
        struct node *newnode = (struct node*)(malloc(sizeof(struct node)));
        newnode->data = n;
        newnode->next = NULL;
        tmp->next = newnode;
        tmp = tmp->next;
        printf("\nDo you want to continue? (y/n): ");
        ch = getche();
    }
    return start;
}

void display(struct node *start){
    if(start == NULL)
        printf("Stack is empty");
    else{
        printf("Elements of stack are");
        struct node *tmp = start;
        while(tmp != NULL){
            printf("\n%d", tmp->data);
            tmp = tmp->next;
        }
    }
}

struct node* push(struct node *start){
    if(start == NULL)
        printf("Stack is empty");
    else{
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        struct node *newnode = (struct node*)(malloc(sizeof(struct node)));
        newnode->data = n;
        newnode->next = NULL;
        struct node *tmp = start;
        while(tmp->next != NULL) 
            tmp = tmp->next;
        tmp->next = newnode; 
    }
    return start;
}

struct node* pop(struct node *start){
    if(start == NULL)
        printf("Stack is empty");
    else{
        struct node *tmp = start;
        struct node *ptmp = NULL;
        while(tmp->next != NULL) {
            ptmp = tmp;
            tmp = tmp->next;
        }
        printf("Popped element is %d", tmp->data);
        free(tmp);
        if(ptmp != NULL)
            ptmp->next = NULL;
        else
            start = NULL;
    }
    return start;
}

