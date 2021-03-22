// /* Program to convert one class to another class */
#include <iostream>
using namespace std;
// class inventory1
// {
// 	int ino,qty;
// 	float rate;
// 	public:
// 		inventory1(int n,int q,float r)
// 		{
// 			ino=n;
// 			qty=q;
// 			rate=r;
// 		}
// 		inventory1()
// 		{
// 			cout<<"\n Inventory1's Object Created";
// 		}
// 		int getino()
// 		{
// 			return(ino);
// 		}
// 		float getamt()
// 		{
// 			return(qty*rate);
// 		}
// 		void display()
// 		{
// 			cout<<endl<<"ino = "<<ino<<" qty = "<<qty<<" rate = "<<rate;
// 		}
// };
// class inventory2
// {
// 	int ino;
// 	float amount;
// 	public:
	
// 	void operator=(inventory1 I)
// 	{
// 		ino=I.getino();
// 		amount=I.getamt();
// 	}
// 	void display()
// 	{
// 		cout<<endl<<"ino = "<<ino<<" amount = "<<amount;
// 	}
// };
// int main()
// {
// 	//clrscr();
// 	inventory1 I1(1001,30,75);
// 	inventory2 I2;
// 	I2=I1;
// 	//inventory2 I2=I1;
// 	I1.display();
// 	I2.display();
// 	//getch();
// return(0);
// }
class x{
    int a;
    public:
    x(){
        a = 10;
    }
    int setx(){
        return a;
    }
    void disp(){
        cout<<"class x data "<<a<<endl;
    }
};
class y{
    int b;
    public:
    y(){
        b = 0;
    }
    void operator=(x obj){
        b = obj.setx();
    }
void disp(){
        cout<<"class y data "<<b<<endl;
    }
};

int main()
{
    x x1;
    y y1;

    x1.disp();
    cout<<"\n before conversion....\n";
    y1.disp();

    y1 = x1;
    cout<<"\n after conversion....\n";
    y1.disp();

    return 0;
}