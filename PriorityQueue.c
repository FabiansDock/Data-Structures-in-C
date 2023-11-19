#include<stdio.h>
#define q_max 10
void push(int q[q_max], int item, int *front, int *rear)
{
  if(*front == -1)
  {
    *front = *rear = 0; q[*front] = item; return;
  }
  
  if(((*rear)+1)%q_max != *front)
  {
    *rear = ((*rear)+1)%q_max;
    q[*rear] = item; 
  }
  return;
}

int pop(int q[q_max], int *front, int *rear)
{
  if(*front == -1)
  {
    return -1;
  }
  else
  if(*front == *rear)
  {
    *front = *rear = -1;
  }  
  else
  {
    ++*front;
  }
  return 0;
}

void display(int size, int *front, int *rear, int pq[size][q_max])
{
  int i, j;
  printf("Priority Queue\n");
    for(i = 0; i < size; ++i)
    {
      printf("%d-->", i+1);
      if(front[i] <= rear[i] && front[i] != -1)
      {
        for(j = front[i]; j <= rear[i]; ++j)
        {
          printf("%d ", pq[i][j]);
        }
        
      }
      if(front[i] > rear[i] && front[i] != -1)
      {
        for(j = 0; j <= rear[i]; ++j)
        {
          printf("%d ", pq[i][j]);
        }
        for(j = front[i]; j < size; ++j)
        {
          printf("%d ", pq[i][j]);
        }  
      }
      printf("\n");
    }
}

void main()
{
  int i, j, size, op = 1, item, priority;
  int front[10], rear[10];
  printf("Enter the size of the queue:\n");
  scanf("%d", &size);
  int pq[size][q_max];
  for(i = 0; i < size; ++i)
  {
    front[i] = rear[i] = -1;
  }
  display(size, front, rear, pq);
  while(op != 3)
  {
    printf("\n1.Insert\n2.Delete\n3.Stop\nEnter your option:");
    scanf("%d", &op);
    switch(op)
    {
      case 1 :printf("Enter the element and its priority:\n");
              scanf("%d %d", &item, &priority); 
              for(i = 0; i < size; ++i)
              {
                if((i+1) == priority)
                {
                  push(pq[i], item, (front+i), (rear+i)); break;
                }
              } break;
      case 2 :for(i = 0; i < size; ++i)
              {
                if(pop(pq[i], (front+i), (rear+i)))
                {
                  continue;
                }
                else
                {
                  break;
                }
              } break;
      case 3 : return; break;
      default: printf("Invalid input!\n"); break;
    }
    display(size, front, rear, pq);
  }
  return;
}
