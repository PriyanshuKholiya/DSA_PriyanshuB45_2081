#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *add;
};

struct node *start,*new1,*temp,*prev;

void Create();
void Insert();
void Delete();
void Display();

int main(){
	
	int choice;
	do{
	printf("----------------QUEUE OPERATIONS MENU--------------------------");
    printf("\n1.Create");
    printf("\n2.Insert");
	printf("\n3.Delete");
	printf("\n4.Display");
	printf("\n5.Exit");
	printf("\n-------------------------------------------------------------------");
	printf("\nEnter your choice");
	scanf("%d",&choice);
	
	switch(choice)
	{ case 1:Create();break;
	  case 2:Insert();break;
	  case 3:Delete();break;
	  case 4:Display();break;
	  case 5:break;
	}
}while(choice!=5);
return 0;}
