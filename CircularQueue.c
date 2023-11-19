#include<stdio.h>
#include<stdlib.h>
int front = -1, rear = -1, size;
char cq[20];
void enqueue(char item)
{
    if(front == -1)
    {
        front = rear = 0;
        cq[front] = item; 
    }
    else
    if((rear+1) % size != front)
    {
        rear = (rear+1) % size;
        cq[rear] = item; 
    }
    else
    {
        printf("Circular Queue is full\n"); 
        return;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Circular Queue is empty\n"); 
    }
    else
    if(front == rear)
    {    front = rear = -1;}
    else
    {
        front = (front+1) % size;
    }
}

void display()
{
    int i = 0;
    if(rear >= front)
    {
        for(i = front; i <= rear; ++i)
        {
            printf("%c ", cq[i]);
        }
    }
    if(rear < front)
    {
        for(i = 0; i <= rear; ++i)
        {
            printf("%c ", cq[i]);
        }
        for(i = front; i < size; ++i)
        {
            printf("%c ", cq[i]);
        }
    }
}

void main()
{
    char op, item;
    printf("Size:\n");
    scanf("%d", &size); getchar();
    printf("a.Insert element\nb.Delete element\nc.Stop\nEnter option:");
    scanf("%c", &op);
    getchar();
    while(op != 'c')
    {   
        switch(op)
        {
            case 'a': printf("Enter the element:\n");
                      scanf("%c", &item); 
                      enqueue(item); getchar();break;
            case 'b': dequeue(); break;
            case 'c': exit(0); break;
            default : printf("Invalid input"); break;
        }
        
        printf("Contents of the circular queue:\n");
        display();
        printf("\na.Insert element\nb.Delete element\nc.Stop\nEnter your option:");
        scanf("%c", &op); 
        getchar();
    }
}