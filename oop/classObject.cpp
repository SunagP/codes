#include<iostream>
using namespace std;


class person{
    private :
    int sal,age;
   
    string name,accNum,add;
   // int bankAcc[3];
    public:
     void read();
     void disp();
     void addSal(person , person);

};

void person :: addSal(person p1 , person p2)
{
   cout<<" Total salary is : "<<p1.sal + p2.sal<<endl ;
}
void person :: read(){
  cout<<"Enter name :"<<endl;
  cin>>name;
  cout<<"Enter account number"<<endl;
  cin>>accNum;
  cout<<"Enter address"<<endl;
  cin>>add;
  /*cout<<"Enter gender"<<endl;
  cin>>gender;*/
  cout<<"Enter salary"<<endl;
  cin>>sal;
}
void person :: disp(){
    //cout<<"basic datails are :"<<endl;
    cout<<endl<<"Name: "<<name<<endl<<"account number :"<<accNum<<endl<<"address :"<<add<<endl;
}
int main(){
  
  person p1,p2;
  p1.read();
  
  p2.read();
  p1.disp();
  p2.disp();
  person temp;
  temp.addSal(p1,p2);
  
}
