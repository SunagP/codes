#include<iostream>
using namespace std;

class hi
{
    public : void disp();
             int compute();
};
inline
void hi :: disp(){
    cout<<"helloooo!!!"<<endl;
}

int main()
{  hi h;
    h.disp();
}