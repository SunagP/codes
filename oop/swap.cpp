#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int *x;
    x=a;
    a=b;
    b=x;
}
int main()
{
    int i=0,j=1;
    swap(&i,&j);
    
    cout<<i<<endl<<j;
    return 0;
}