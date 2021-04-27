#include <iostream>
using namespace std;

class test{
    public:
     int x,y;
     test(){
         x=10;
         y=20;
     }

     void math(test t){
         t.x *= 2;
         t.y /= 2;
     }
     void disp(){
         cout<<x<<endl;
          cout<<y<<endl;

     }
};

int main(){
    test t;
    t.disp();
    t.math(t);
    t.disp();
    // test *t1 = new test();

    // t1->disp();
    // t1->math(t);
    // t1->disp();


    return  0;

}