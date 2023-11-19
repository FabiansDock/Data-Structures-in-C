#include<stdio.h>
#include<stdlib.h>

int size, front = -1, rear = -1;
int deq[10];
void insert_front(char item)
{
    if(front == -1)
    {
        front = rear = 0; deq[front] = item;
    }
    else
    if(front == 0 && rear != size-1)
    {
        front = size-1; deq[front] = item;
    }
    else
    if((front-1) != rear)
    {
        --front; deq[front] = item;
    }
    else
    { printf("Queue is full");}
}

void insert_rear(char item)
{
    if(front == -1)
    {
        front = rear =0; deq[rear] = item;
    }
    else
    if((rear+1)%size != front)
    {
        rear = (rear+1)%size; deq[rear] = item;
    }
    else
    {
        printf("Queue is full");
    }
}

void delete_front()
{
    if(front == -1)
    {
        printf("Queue is empty");
    }
    else
    if(front == rear)
    {
        front = rear = -1;
    }    
    else    
    { front = (front+1)%size; }
}

void delete_rear()
{
    if(front == -1)
    {
        printf("Queue is empty");
    }
    else
    if(front == rear)
    {
        front = rear = -1;
    } 
    else   
    if(rear == 0)
    {
        rear = size-1;
    }
    else
    {
        --rear;
    }
}

void display()
{
     int i =0;
     if(front <= rear)
        {
            for(i = front; i <=rear; ++i)
            {
                printf("%c", deq[i]);
            }
        }
        if(front > rear)
        {
            for(i = front; i < size; ++i)
            {
                printf("%c", deq[i]);
            }
            for(i = 0; i <= rear; ++i)
            {
                printf("%c", deq[i]);
            }
        }
}

void main()
{
    int i, op;
    char item;
    printf("Enter the size:");
    scanf("%d", &size);
    
    while(1)
    {
        printf("\n1.Insert front\n2.Insert rear\n3.Remove front\n4.Remove rear\n5.Display\n6.Stop\nEnter option:");
        scanf("%d", &op); getchar();
        switch(op)
        {
            case 1: printf("Enter the element:\n");
                      scanf("%c", &item); 
                      insert_front(item); break;
            case 2: printf("Enter the element:\n");
                      scanf("%c", &item); 
                      insert_rear(item); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: printf("Contents:\n"); display(); break;
            case 6: exit(0); break;
            default: printf("Invalid input"); break;
        }
    }
}