#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start=NULL,*newnode,*temp,*prev;

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

void Create() {//creation of a basic linked list
    int n, i, num;
    printf("Enter the number of elements to be inserted: ");//input no of elements
    scanf("%d", &n);
    if (n <= 0) {//check if negative or zero
        printf("Invalid size\n");
        return;
    }
    for (i = 0; i < n; i++) {//input elements
        printf("Enter element %d: ", i + 1);
        scanf("%d", &num);
        newnode = (struct node *)malloc(sizeof(struct node));//for each iteration keep allocating memory for the newnode
        if (newnode == NULL) {//check if memory is allocated
            printf("Memory allocation failed\n");
            return;
        }
        newnode->data = num;
        newnode->next = NULL;
        if (start == NULL) {//for first node
            start = newnode;
        } else {//add newnnode to the end
            temp = start;
            while (temp->next != NULL) {//run the loop till last element is encountered
                temp = temp->next;
            }
            temp->next = newnode;//link the newnode with the current last element
        }
    }
    printf("Queue created successfully\n");
}

void Insert() {//insertion at the end in a LL
    int num;
    printf("Enter the element to insert: ");//input element
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));//allocate memory to it
    if (newnode == NULL) {//if memory isn't available
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = num;//create newnode
    newnode->next = NULL;
    if (start == NULL) {//if there was no element before insertion
        start = newnode;
    } else {
        temp = start;
        while (temp->next != NULL) {//run the loop it it encounters the last node
            temp = temp->next;
        }
        temp->next = newnode;//link newnode the to the current last node
    }
    printf("Element inserted successfully\n");
}

void Delete() {//delete from beginning in a LL
    if (start == NULL) {//if the queue isn't created
        printf("Queue is empty, nothing to delete\n");
        return;
    }
    temp=start;//point start using temp
    start = start->next;//move start forward
    free(temp);//free temp in order to delete the element
    printf("Element deleted successfully\n");
}

void Display() {
    if (start == NULL) {//if no queue was created
        printf("Queue is empty\n");
        return;
    }
    temp = start;
    printf("Queue elements: ");
    while (temp != NULL) {//run the loop till temp surpasses the last element
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
