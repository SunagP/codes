#include<stdio.h>
#include<math.h>

void toh(int n,char a,char b , char c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        printf("Move disc %d from %c to %c \n",n,a,c);
        toh(n-1,b,a,c);
    }
}

int main()
{
    int n;
    printf("Enter number of discs\n");
    scanf("%d",&n);
    printf("Total number of steps required to move %d discs is %.0f\n",n,pow(2,n)-1);
  
    toh(n,'a','b','c');
    return 0;
}