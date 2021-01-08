#include<iostream>
using namespace std;
//float vol(int r, int h)
void hello();
float vol(int r=1,int h=1)
{
    return 3.14*r*r*h;
}
int main()
{
    float x;
    x=vol();
    cout<<"volume is "<<x<<endl;
    x=vol(30);
    cout<<"volume is "<<x<<endl;
    x=vol(20,10);
    cout<<"volume is "<<x<<endl;
    hello();
    return 0;
}