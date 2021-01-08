#include<stdio.h>     
#include<string.h>      
#define MAX 50              
float stack[MAX];             
char post[MAX];            
int top=-1;                 
void push(int tmp);      
void evaluate(char c);  
float pop();        
int main()
{
   int i,l;
   
   printf("Insert a postfix expression : ");
   gets(post);                    
   l=strlen(post);             
   for(i=0;i<l;i++)
   {
      if(post[i]>='0' && post[i]<='9')
      {
          push(i);             
      }
      if(post[i]=='+' || post[i]=='-' || post[i]=='*' ||
      post[i]=='/' || post[i]=='^')       
      {
          evaluate(post[i]);            
      }
   }  if(top>0)
   {
       printf("invalid postfix expression\n");
   }  
   else                  
     printf("\n\nResult : %f",stack[top]);
 return 0;  
}
float pop()
{
    
    
    return stack[top];
    top--;

    
}
void push(int tmp)          
{
   top++;                              
   stack[top]=(float)(post[tmp]-48);    
}

void evaluate(char c)       
{
   float a,b;
   float ans;        
   a=pop();       
        
   top--;               
   b=pop();       
   
   top--;                
   switch(c)     
   {
      case '+':          
          ans=b+a;
          break;
      case '-':           
          ans=b-a;
          break;
      case '*':            
          ans=b*a;
          break;
      case '/':           
          ans=b/a;
          break;
      case '^':      
          ans=(int)b^(int)a;
          break;
      default:
          ans=0;      
   }
   top++;             
   stack[top]=ans;        
}