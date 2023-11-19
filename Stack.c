#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
}*head, *ptr, *ptr1, *ptr2, *temp;

void display()
{
	ptr1 = head;
	if(ptr1->link == NULL)
	{
		printf("Stack is empty"); return;
	}
	while(ptr1->link != NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->link;
		printf("%d ", ptr1->data);
	}
}

void push()
{
	ptr2 = ptr1;
	ptr = malloc(sizeof(struct node));
	printf("Enter the item:");
	scanf("%d", &ptr->data);
	ptr->link = NULL;
	ptr1->link = ptr;
	ptr1 = ptr;
}

void pop()
{
	if(ptr1 == head)
	{
		printf("Stack underflow"); return;
	}
	else
	{
		temp = ptr1;
		ptr2->link = NULL;
		display();
		free(temp);
	}
}


void main()
{
	int op;
	head = malloc(sizeof(struct node));
	head->data = '\0';
	head->link = NULL;
	ptr1 = head;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display the contents of the stack\nEnter your option:");
		scanf("%d", &op);
		switch(op)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			default:printf("Invalid input"); break;
		}
	}
}
