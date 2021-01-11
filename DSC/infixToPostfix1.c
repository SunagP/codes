#include<stdio.h>
#include<stdlib.h>
int top=-1;
void InToPost(char*,char*);
int isOperand(char);
void push(char*,char);
char pop(char*);
int main ()
{
    char stack[100]={'\0'},exp[100]={'\0'};
    int stack3[100];
    printf("enter infix expression : ");
    scanf("%s",exp);
    printf("postfix expression is : ");
    InToPost(exp,stack);
    return 0;
}
int isOperand(char c)
{
    if(c>='0'&&c<='9'||c>='a'&&c<='z'||c>='A'&&c<='Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void push(char *stack,char a)
{
    top++;
    stack[top]=a;
}
char pop(char* stack)
{
    char num;
    num=stack[top];
    stack[top]=0;
    top--;
    return num;
}
int priority(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void InToPost(char* exp,char* stack)
{
    int i=0;
    while(exp[i]!='\0')
    {
        if(isOperand(exp[i]))
        {
            printf("%c",exp[i]);
        }
        else
        {
            if(top==-1)
            {
                push(stack,exp[i]);
            }
            else if(exp[i]=='(')
            {
                push(stack,exp[i]);
            }
            else if(exp[i]==')')
            {
                while(stack[top]!='(')
                {
                    printf("%c",pop(stack));
                }
                pop(stack);
            }
            else if(priority(exp[i])>priority(stack[top]))
            {
                push(stack,exp[i]);
            }
            else
            {
                while(priority(stack[top])>=priority(exp[i]))
                {
                    printf("%c",pop(stack));

                }
                push(stack,exp[i]);
            }
            
        }
        
        i++;
    }
    while(top!=-1)
    {
        printf("%c",pop(stack));
    }
}