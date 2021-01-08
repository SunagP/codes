#include<iostream>
using namespace std;

class dist{
 public:
  float feet,inches;
  void read(){cin>>feet>>inches;}
  dist add(dist d1 , dist d2){
      dist d3;
      d3.feet=d1.feet+d2.feet;
      d3.inches=d1.inches+d2.inches;
      return d3;
      }
      /*dist add(dist d2){
          dist d3;
      d3.feet=feet+d2.feet;
      d3.inches=inches+d2.inches;
      return d3;
      }*/
  };


int main()
{ float d1Total,d2Total;
 dist d1,d2,d3;
 d1.read();
 d2.read();
 d3=d3.add(d1,d2);
 //d3=d1.add(d2);//implicitly d1 is sent to function
 cout<<"addition of distance is"<<endl;
 cout<<d3.feet<<endl<<d3.inches;

}