#include<stdio.h>
#include<stdlib.h>
int stack[20],top=-1;
int max=10;
int isempty();
int isfull();
void disp();
void push();
void pop();
void peek();

int main()
{
    int x;
    while(x)
    {    printf("\n1 to push \n2 to pop\n3 to peek\n4 to display\n0 to exit\n");
    scanf("%d",&x);
        switch(x)
        {
        case 1: push();
        break;
        case 2 : pop();
        break;
        case 3 : peek();
        case 0 : break;
        case 4 : disp();
        break;
        }
    }
    return 0;
}
void push()

{   if(isfull())
printf("can't perform\n");
else
{
    int num;
    top++;
    printf("Enter an element to push onto stack\n");
    scanf("%d",&num);
    stack[top]=num;
}
}
void pop()
{
    if(isempty())
    {
        printf("no elements to pop\n");
    }
    else{
    printf("\n%d is removed\n",stack[top]);
    top--;
    }
}
int isempty()
{
    if(top==-1)
    {
        printf("stack under flow\n");
        return 1;
    }
    else
    {
        return 0;
    }
    

}
int isfull()
{
    if(top==max-1)
    {
        printf("Stack over flow\n");
        return 1;
    }
    else
    {
        {return 0;}
    }
    
}
void disp()
{
    int i;
    if(isempty())
    {
        printf("no elements\n");
        return;

    }
    else
    {   printf("elements are\n");
        for( i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
    }
    
}
void peek()
{   if(isempty())
{
    printf("cannot peek\n");
} 
  else{
    printf("%d is at top\n",stack[top]);
  }
}