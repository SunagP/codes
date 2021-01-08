#include <iostream>
using namespace std;
int x;

int main()
{
    int i = 0, &r1 = i; double d = 0, &r2 = d;
 r2 = 3.14159;
 //r2 = r1;
 r1=r2;
 i = r2;
 r1 = d;
 cout<< &r2;
 cout<<&d;
}
