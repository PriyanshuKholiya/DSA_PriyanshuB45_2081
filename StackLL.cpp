#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

void create();
void display();
void push();
void pop();

struct node *start=NULL,*newnode,*tmp,*ptmp;//assigned NULL to start so as to later compare it to know if the stack is empty

int main(){
	int choice;
	do{
	printf("\n---Stack operation menu---");
	printf("\n1.Create\n2.Push\n3.Pop\n4.Display\n5.Exit");
	printf("\n----------------------------");
	printf("\nEnter your choice");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:create();break;
		case 2:push();break;
		case 3:pop();break;
		case 4:display();break;
	}
	}while(choice!=5);
	return 0;	
}

void create(){
	int n;
	char ch;
	printf("Enter an element ");
	scanf("%d",&n);// this is redundant 
	start=(struct node*)(malloc(sizeof(struct node)));
	start->data=n;
	start->next=NULL;
	tmp=start;//start should always point to the first node so we use tmp to traverse in the list
	printf("Do you want to continue");
	ch=getche();// to input a single character without the use of scanf
	while(ch=='y'||ch=='Y'){
		printf("\nEnter an element ");
		scanf("%d",&n);
		newnode=(struct node*)(malloc(sizeof(struct node)));
		newnode->data=n;
		newnode->next=NULL;
		tmp->next=newnode;
		tmp=tmp->next;
		
		printf("\nDo you want to continue");
		ch=getche();
	}
}

void display(){
	if(start==NULL)
	printf("Stack is empty");
	else{
		printf("Elements of stack are");
		tmp=start;
		while(tmp!=NULL){
			printf("\n%d",tmp->data);
			tmp=tmp->next;
		}
	}
}

void push(){
	if(start==NULL)
	printf("Stack is empty");//ie stack is not created yet 
	else{
		int n;
		printf("Enter an element ");
		scanf("%d",&n);
		newnode=(struct node*)(malloc(sizeof(struct node)));//since we are assigning memory to a pointer we have typecasted malloc struct node to a struct node pointer
	    newnode->data=n;
	    newnode->next=NULL;
	    tmp=start;// we dont want start to move so we use tmp to traverse the stack
	    while(tmp->next!=NULL)//it will move upwards till it encounters the last node else if we equate tmp to null here we will miss the last node
	    { tmp=tmp->next;
		}
		tmp->next=newnode;
	}
}

void pop()//imitation of delete from end in a linked list
   {
   if(start==NULL)
   printf("list not found");
   else
   { tmp=start;
    
   while(tmp->next!=NULL)//tmp moves till its next encounters NULL hence tmp becomes the last node
   {
    ptmp=tmp;//tracks the value of tmp
	tmp=tmp->next;//moves forward
   }
   printf("Popped element is %d",tmp->data);
   ptmp->next=NULL;
   free(tmp);
}
}

