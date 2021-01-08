#include<iostream>
using namespace std;


class mathworks
{
    public:
     float add(float,float);
     float sub(float,float);
     float div(float,float);
     float mul(float,float);

};
inline
float mathworks :: add(float a , float b)
{
    return a+b;
}
inline
float mathworks :: sub(float a , float b)
{
    return (a-b);

}
inline
float mathworks :: mul(float a , float b)
{
    return a*b;
}
inline
float mathworks :: div(float a , float b)
{  if(b!=0){
    return a/b;
}
   else
   {
       cout<<"cannot divide by 0"<<endl;
   }
   
}
int main()
{
    mathworks m;
    float a,b;
    float x;
    cout<<"Enter two numbwrs to perform mathematical operations"<<endl;
    cin>>a;
    cin>>b;
    
    x= m.add(a,b);
    cout<<"addition = "<<x<<endl;
    
    x =  m.sub(a,b);
    cout<<"subtraction = "<<x<<endl;
    
   x =  m.mul(a,b);
    cout<<"multiplication = "<<x<<endl;
    
   x = m.div(a,b);
    cout<<"division = "<<x<<endl;
    return 0 ;
}