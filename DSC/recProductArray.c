#include<stdio.h>

int prod(int n,int *arr){
    if (n == 0)
     return arr[n];
    return(arr[n]*(prod(n-1,arr)));

}

int main()
{
    int x;
    int y[2];
    y[0] = 2;
    y[1] = 3;
    x = prod(1,y);
    printf("%d",x);

}