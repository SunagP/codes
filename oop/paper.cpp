#include<iostream>
using namespace std;

int mod(int x,int y)
{
    return((x%10),(y%10));
}

int main()
{
  cout<<mod(5,28);
}