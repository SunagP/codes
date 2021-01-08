#include<stdio.h>

int mutiplication(int x , int y)
{
    if(y>0)
     return (x+mutiplication(x,y-1));
    else 
      return 0;
}
int main()
{
    int x,y;
    printf("Enter 1st Numbers : \n");
    scanf("%d",&x);
    printf("Enter 2nd Numbers : \n");
    scanf("%d",&y);
    printf("product of %d and %d is %d",x,y,mutiplication(x,y));
    return 0;
}