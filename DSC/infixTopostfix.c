#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int isnum(char x)
{
    if(x>'0'&& x<'9')
    return (int)x;
}

int order(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{    
    char exp[100];
    char *e, x;
    char *a;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    int arr[10];
    while(*e != '\0')
    {    
        if(isalnum(*e))
           { printf("%c ",*e);
            
            
           }
       /* if(isnum(*e))
           printf("%c",*e);*/
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(order(stack[top]) >= order(*e))
                printf("%c ",pop());
                
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
        
    }
    
   
    return 0;
   
}