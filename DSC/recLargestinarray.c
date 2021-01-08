#include<stdio.h>
int big(int x,int *b,int large)
{
if(x==0)
{
return large;
}
else
{
if(b[x-1]>large)
{
large=b[x-1];
}
return big(x-1,b,large);
}
}
int main()
{
int n,j,large;
printf("enter the size of array:");
scanf("%d",&n);
int a[n];
printf("enter %d numbers : ",n);
for(j=0;j<n;j++)
{
scanf("%d",&a[j]);
}
large=a[0];
printf("%d is largest element in array",big(n,a,large));
return 0;
}