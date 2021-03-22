#include<iostream>
using namespace std;

class shape{
    protected:
    int h,w;
    public:
     virtual void area() = 0;
    void getdata(){
        cin>>h>>w;
    }
};

class rect : public shape{
  public:
  void area(){
      cout<<h*w<<" is rect area\n";
  }
};
class tri : public shape{
  public:
  void area(){
      cout<<h*w/2<<" is tri area\n";
  }
};

int main()
{
    rect r;
    tri t;
    shape *s;
    cout<<"dim of rect\n";
    s = &r;
    
    s->getdata();
    s->area();
    cout<<"dim of tri\n";
    s = &t;
    s->getdata();
    s->area();
    // r.getdata();
    // r.area();
    // cout<<"dim of tri\n";
    // t.getdata();
    // t.area();
}