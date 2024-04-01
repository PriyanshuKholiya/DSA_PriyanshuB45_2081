#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *start = NULL;

void Create(struct node **);
void Insert(struct node **);
void Delete(struct node **);
void Display(struct node *);

int main() {
	int choice;
	do {
		printf("----------------QUEUE OPERATIONS MENU--------------------------");
    	printf("\n1.Create");
    	printf("\n2.Insert");
		printf("\n3.Delete");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\n-------------------------------------------------------------------");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
	
		switch(choice) {
			case 1:
				Create(&start);
				break;
			case 2:
				Insert(&start);
				break;
			case 3:
				Delete(&start);
				break;
			case 4:
				Display(start);
				break;
			case 5:
				break;
			default:
				printf("Invalid choice!\n");
				break;
		}
	} while(choice != 5);
	return 0;
}

void Create(struct node **start) {
	int n, num, i;
	struct node *newnode, *temp;
	printf("Enter the number of elements to be inserted: ");
	scanf("%d", &n);
	if (n <= 0) {
		printf("Invalid size\n");
		return;
	}
	for (i = 0; i < n; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d", &num);
		newnode = (struct node *)malloc(sizeof(struct node));
		if (newnode == NULL) {
			printf("Memory allocation failed\n");
			return;
		}
		newnode->data = num;
		newnode->next = NULL;
		if (*start == NULL) {
			*start = newnode;
		} else {
			temp = *start;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	printf("Queue created successfully\n");
}

void Insert(struct node **start) {
	int num;
	struct node *newnode, *temp;
	printf("Enter the element to insert: ");
	scanf("%d", &num);
	newnode = (struct node *)malloc(sizeof(struct node));
	if (newnode == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	newnode->data = num;
	newnode->next = NULL;
	if (*start == NULL) {
		*start = newnode;
	} else {
		temp = *start;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
	printf("Element inserted successfully\n");
}

void Delete(struct node **start) {
	struct node *temp;
	if (*start == NULL) {
		printf("Queue is empty, nothing to delete\n");
		return;
	}
	temp = *start;
	*start = (*start)->next;
	free(temp);
	printf("Element deleted successfully\n");
}

void Display(struct node *start) {
	struct node *temp = start;
	if (temp == NULL) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

