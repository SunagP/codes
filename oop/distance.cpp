#include <iostream>

using namespace std;
struct dist
{
    int f,inch;
    
};
void disp(struct dist d)
{
    cout<<"Distance is "<<d.f+(d.inch/12)<<" feet "<<d.inch%12<<" inches"<<endl;
}
void disp(int f)
{
    cout<<"Distance is "<<f/12<<" feet "<<int(f)%12<<" inches"<<endl;
}
int main()
{
    struct dist d;
    cout<<"Enter distance in feet and inches"<<endl;
    cin>>d.f>>d.inch;
    disp(d);
    disp(20);
    return 0;
}