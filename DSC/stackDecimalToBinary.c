#include<stdio.h> 
#include<math.h>

int max=20;

int top=-1, stk[20];
void push(int);
int pop();

int main() 
{
     int i,num,x,count=0,s, bin=0;
     printf("Enter any decimal number: ");
     scanf("%d",&num);
     while(num>0)
     {
         if(num==1)
             push(num);
         else
         {
             x = num%2;
             push(x);
          }
         num/=2;
         count++;
     }

for(i=0;i<count;i++)
{
    s = pop();
    bin = bin + s*pow(10,(count-1-i));
}

printf("\nEquivalent Binary number is %d",bin);
return 0;
}

void push(int n)
{ 
     if(top == max-1)
     {
          printf("Error! Overflow");
          return;
     }
     stk[++top] = n;
 }

 int pop()
 {
     int y;
     if(top == -1)
     {
          printf("Error! Underflow");
          return;
     }
     y = stk[top];
     top --;;
     return y;
  }