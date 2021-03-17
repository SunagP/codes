#include<stdio.h>
int sec(char *arr , int n , char key){
    if(n<1)
       return -1;
    if(arr[n] == key)
     return n;
    sec(arr,n-1,key);
} 

int main()
{
    char x[4] = "abcd";
    int a;
    a = sec(x,3,'b');
    printf(" found at position %d",a+1);
}