#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*head, *ptr, *ptr1;

void display()
{
    ptr1 = head;
    if(ptr1->link == NULL)
    {
        printf("Queue is empty"); return;
    }
    printf("Contents:\n");
    while(ptr1->link != NULL)
    {
        ptr1 = ptr1->link;
        printf("%d ", ptr1->data);
    }
}

void enqueue()
{
    ptr = malloc(sizeof(struct node));
    if(ptr == NULL)
    {  printf("Memory couldn't be allocated"); return; }
    printf("Enter the data:");
    scanf("%d", &ptr->data);
    ptr1->link = ptr;
    ptr->link = NULL;
    ptr1 = ptr;
}

void dequeue()
{
    if(head->link == NULL)
    { printf("Queue is empty"); return; }
    ptr1 = head->link;
    head->link = ptr1->link;
    free(ptr1);
}

void main()
{
    int op;
    head = malloc(sizeof(struct node));
    if(head == NULL)
    {  printf("Memory couldn't be allocated"); return; }
    head->data = '\0';
    head->link = NULL;
    ptr1 = head;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your option:");
        scanf("%d", &op); 
        switch(op)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            default: printf("Invalid input"); break;
        }
    }
}