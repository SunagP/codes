#include<stdio.h>
int queue[5][20];
int max=5,front=0,rear=0;
int isempty(void)
{
    if(front==rear)
    {
        return 1;
    }
    return 0;
}
int isfull(void)
{
    if(rear==max)
    {
        return 1;
    }
    return 0;
}
void enqueue()
{
    if(isfull())
    {
        printf("queue is full\n");
    }
    else
    {
        printf("enter document to be printed : ");
        scanf("%s",&queue[rear]);
        rear++;
    }
    //printf("%d %d ",front,rear);
}
void dequeue()
{
    if(isempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("%s is printed.....\n",queue[front]);
        front++;
    }
}
void display()
{
    if(isempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%s\n ",queue[i]);
            i++;
            printf("\n");
        }
    }
}
void peek()
{
    if(isempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("the top document is %s",queue[front]);

    }

}
    
int main()
{
    int x=1;
    while(x)
    {
        printf("enter 1 to input the document to be printed\nenter 2 to print the top document in the queue\nenter 3 to display the top document name\nenter 4 to display the order of printing\nenter 0 to exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1 : enqueue();
            break;
            case 2 : dequeue();
            break;
            case 3 : peek();
            break;
            case 4 : display();
            break;
            case 0 : break;
            default : printf("invalid\n");
            break;
        }
    }
}