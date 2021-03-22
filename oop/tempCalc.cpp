#include <iostream> 
using namespace std; 

template<class T>
class calculator
{
    public:
    T x;
    T y;
    char z;
    calculator(){
        x=0;
        y=0;
        // z='NULL';
    }
void setData(){
    cout<<"Enter data 1 ";
    cin>>x;
    cout<<"Enter data 2 ";
    cin>>y;
    
}
    
void calc()

{   cout<<"Enter operation\n";
    cin>>z;
  switch(z)
  {
      case '+': cout<<x+y<<endl;break;
      case '-': cout<<x-y<<endl;break;
      case '*': cout<<x*y<<endl;break;
      case '/': if(y!=0)
                 cout<<x/y<<endl;break;
  }
}
};
int main()
{  calculator<int> c,c1;
    c.setData();
    c.calc();
    c1.setData();
    c1.calc();
}