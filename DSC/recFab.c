#include<stdio.h>
int fab(int);
int main()
{
  int n, m= 0, i;
  printf("Enter Total terms:");
  scanf("%d", &n);
  printf("Fibonacci series terms are: ");
  while(m!=n)
  {
    printf("%d ",fab(m));
    m++;
  }
  return 0;
}
int fab(int n)
{
if(n == 0 || n == 1)
return n;
else
return(fab(n-1) + fab(n-2));
}