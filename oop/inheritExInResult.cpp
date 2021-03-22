#include<iostream>
using namespace std;

class ex{
    protected:
    int em;
    public:
     ex(int m){em=m;}
      ex(){em=0;}
};
class in{
    protected:
    int im;
    public:
    in(int m){im=m;}
    in(){im=0;}
};

class r :public ex , public in{
  int avg;
  public:
  r(){avg=0;}
   void result(){
       avg = (im+em)/2;
       if(avg>=75)
        cout<<"A Grade\n";
       else{
           cout<<"B Grade\n";
       }

   }
};
int main(){
    ex e(100);
    in i(99);
    r R;
    R.result();

    return 0;

}