#include<iostream>
using namespace std;

struct Circle
{
    int xCo, yCo;
    char colorName[10];
    char fillType[10];
};

void show(Circle c)
    {
        cout<<"Displaying information:\n";
        cout<<"Circle is "<<c.colorName<<" edged with "<<c.fillType<<" type."<<endl;
    }

int main()
{
    int c;
    struct Circle c1 = {10,20,"Green","Full"};
    struct Circle c2 = {11,21,"Blue","Semi"};
    struct Circle c3 = {12,22,"Red","Void"};
    cout<<"Enter which circle type you want to view: (1/2/3)"<<endl;
    cin>>c;
    if(c==1)
       show(c1);
    else if(c==2)
       show(c2);
    else if(c==3)
       show(c3);
    else
       cout<<"Wrong input"<<endl;
    return 0;
}