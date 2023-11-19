#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
}*ptr, *head, *p, *temp;

void display()
{
	printf("Linked list\n");
	ptr = head->link;
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
}

void insert_at_beg()
{
	ptr = head;
	ptr = ptr->link;
	p = malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d", &p->data);
	head->link = p;
	p->link = ptr;
}

void insert_at_end()
{
	ptr = head;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	p = malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d", &p->data); 
	ptr->link = p;
	p->link = NULL;
}

void insert_at_spec(int pos)
{
	ptr = head;
	for(int i = 1; i <= pos; ++i)
	{
		ptr = ptr->link;
	}
	p = malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d", &p->data); 
	p->link = ptr->link;
	ptr->link = p;
}

void delete_from_beg()
{
	temp = head->link;
	head->link = temp->link;
	free(temp);
}

void delete_from_end()
{
	struct node* ptrg;
	ptr = head;
	while(ptr->link != NULL)
	{
		ptrg = ptr;
		ptr = ptr->link;
	}
	temp = ptr;
	ptrg->link = NULL;
	free(temp);
}

void delete_from_spec(int pos)
{
	struct node* ptrg;
	ptr = head;
	for(int i = 1; i <= pos; ++i)
	{
		ptrg = ptr;
		ptr = ptr->link;
	}
	temp = ptr;
	ptrg->link = ptr->link;
	free(temp);
}

void main()
{
	int op, pos;
	head = malloc(sizeof(struct node));
	head->data = '\0';
	head->link = NULL;
	ptr = head;
	while(1)
	{
		printf("\n1.Display\n2.Insert at beginning\n3.Insert at end\n4.Insert at specified psoition\n5.Delete from beginning\n6.Delete from end\n7.Delete from specified position\n8.Stop\nEnter your option:");
		scanf("%d", &op);
		switch(op){
			case 1:display(); break;
			case 2:insert_at_beg(); break;
			case 3:insert_at_end(); break;
			case 4:printf("At position:");
				   scanf("%d", &pos);
				   insert_at_spec(pos); break;
			case 5:delete_from_beg(); break;
			case 6:delete_from_end(); break;
			case 7:printf("From position:");
				   scanf("%d", &pos);
				   delete_from_spec(pos); break;
			case 8:return; break;
			default:printf("Invalid input"); break;
		}
	}
}