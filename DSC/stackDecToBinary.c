#include<stdio.h>

 #define max 100

 int stack[max],top=-1,i,x;

      
  void push (int x)
  {
    ++top;
    stack [top] = x;

   }
  int pop ()
   {
    return stack[top];

   }

    
  int  main()
  {
    int num, total = 0,x;
    printf( "Enter a decimal: ");
    scanf("%d",&num);

    while(num > 0)
     {
       total = num % 2;
       push(total);
       num /= 2;
     }

    for(i=top;top>-1;top--)
    {
     x = pop ();
     printf("%d",x);
    }
  }