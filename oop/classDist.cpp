#include<iostream>
using namespace std;

class dist{
public:
float feet,inches;

};

int main()
{ float d1Total,d2Total;
 dist d1,d2;
 cout<<"Enter class 1 distance in feet ,inches"<<endl;
 cin>>d1.feet>>d1.inches;
d1Total = d1.feet + float(d1.inches)/12;
cout<<"Enter class 2 distance in feet ,inches"<<endl;
 cin>>d2.feet>>d2.inches;
d2Total = d2.feet + float(d2.inches)/12;
cout<<"total distance  is "<<d1Total+d2Total<<endl;

}