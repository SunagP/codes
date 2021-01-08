#include <stdio.h>
#define SIZE 3

void enQueue(int);
void deQueue();
void display();
void peek();

int items[SIZE], front = -1, rear = -1;

int main() {
  int x;
  int a;
  while(x)
  {
      printf("\n1 EnQueue \n2 DeQueue \n3 Peek \n4 display\n0 Exit\n");
      scanf("%d",&x);
      switch(x)
      {   
          case 1 : printf("Enter Number to enqeus :\n");
                   scanf("%d",&a);
                   enQueue(a);
                   break;
          case 2: deQueue();
                  break;
          case 3 : peek();
                  break;
          case 4 : display();
                  break ; 
        

      }
  }

  return 0;
}

void enQueue(int value) {
  if ((rear == SIZE - 1 && front == 0)|| rear == front-1)
    printf("\nQueue is Full!\n");
  else {
    if (front == -1)
      front = 0;
    rear=(rear+1)%SIZE;
    /*if(rear==SIZE)
     rear=0;*/
    items[rear] = value;
      

    printf("\nInserted : %d\n", value);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!\n");
  else {
    printf("\nDeleted : %d\n", items[front]);
    //front++;
    if (front == rear)
      front = rear = -1;
      else
      front=(front+1)%SIZE;
  }
   front=(front+1)%SIZE;
  /*if(front==SIZE-1)
  {
    front=0;
    
  }*/
 /* else
  {
    front++;
  }*/
  
}
void peek()
{   if (front == -1)
    printf("\nQueue is Empty!\n");
  else {
    printf("%d is in the first position \n",items[front]);
  }
}

void display() {
  int f=front,r=rear,i;
  if (rear == -1)
    printf("\nQueue is Empty!\n");

 /* if(r>=f)
    while(rear>=front)
    {
      printf("%d ",items[f]);
      f++;
      
    }
    else
    { while(f<=SIZE-1)
    {
       printf("%d",items[front]);
       f++;
    }
    f=0;
    while(f<=r)
    {
      printf("%d",items[f]);
      f++;
    }*/
    else{
    for(i=f;i!=r;i=(i+1)%SIZE)
    {
      printf("%d \n",items[i]);
    }
    printf("%d",items[i]);
      
    }
}
    
    
