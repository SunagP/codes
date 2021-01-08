 #include <iostream>
using namespace std;
class complex{
   int real,imag;
   public:
     void read();
     void disp();
    friend complex add(int , complex);
    friend complex add(complex , complex);

};

void complex :: read()
{
    cout<<"Enter real part"<<endl;
    cin>>real;
    cout<<"Enter imginary part"<<endl;
    cin>>imag;
}
void complex :: disp()
{
    cout<<real <<" + "<<imag<<"i"<<endl;
}
complex add(int x , complex y)
{   complex c;

    c.real = y.real + x ;
    c.imag=y.imag;
    return c;

}
complex add(complex x , complex y)
{
    complex total;
    total.real = x.real + y.real;
    total.imag = x.imag + y.imag;
    return total;

}
int main()
{
    complex c1,c2,c3,c4;
    c1.read();
    c2.read();
    c4=add(6,c2);
    c3=add(c1,c2);
    c1.disp();
    c2.disp();
    c3.disp();
    c4.disp();

}