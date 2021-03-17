#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
}*front,*rear;
 
int peek();
void enq(int data);
void deq();

void display();
int main()
{
    int val,p;
     int x=1;
    while(x)
  {
      printf("\n1 EnQueue \n2 DeQueue \n3 Peek \n4 display\n0 Exit\n");
      scanf("%d",&x);
      switch(x)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &val);
            enq(val);
            break;
        case 2:
            deq();
            break;
        case 3:
            p = peek();
            if (p != 0)
                printf("Front element : %d\n", p);
            else
                printf("\n queue is empty\n");
            break;
        case 4:
            display();break;
        
        }
    }
    return 0;



}
 



void enq(int data)
{    struct node *temp;
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->link = NULL;
        rear->data = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->link = temp;
        temp->data = data;
        temp->link = NULL;
 
        rear = temp;
    }
    
}
 

void display()
{
   struct node *front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }printf("Queue elements are : ");
    while (front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->link;
    }
    if (front1 == rear)
        printf("%d", front1->data);
}
 

void deq()
{
   struct node *front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n empty queue\n");
        return;
    }
    else
        if (front1->link != NULL)
        {
            front1 = front1->link;
            printf("\n Dequed value : %d\n", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d\n", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        
}
 

int peek()
{
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}
 









