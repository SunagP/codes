#include <iostream>

using namespace std;
struct room
{
    float len,wid;
    
}r;
struct distance 
{
    int feet,in;
}l,w;

int main()
{
    cout<<"enter length of the room (feet)"<<endl;
    cin>>l.feet;
    cout<<"enter length of the room (inches)"<<endl;
    cin>>l.in;
    r.len=(float)l.in/12+l.feet;
    cout<<"enter width of the room (feet)"<<endl;
    cin>>w.feet;
    cout<<"enter width of the room (inches)"<<endl;
    cin>>w.in;
    r.wid=(float)w.in/12+w.feet;
    cout<<"area in square feet is : "<<(r.len*r.wid)<<endl;
    return 0;

}