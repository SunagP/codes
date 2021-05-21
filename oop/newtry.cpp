#include<iostream>
 using namespace std;

 class a{
    public :
    int a;

};
class b:public a{
  public :int x=10;
  void disp(){
      cout<<x;
  }
};

int main(){
    a *obja;
    b objb;

    obja = &objb;

    objb.disp();
    // obja.disp();




}