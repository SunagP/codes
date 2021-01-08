#include<iostream>
using namespace std;


class person{
    private :
    int sal,age;
   
    string name,add;
    
    public:
     void read();
     void disp();
     person():age(0),name("\0"),add("\0"),sal(0){}
    person(int ageVal , string nameVal,string addVal,int salVal  ){}
};
void person :: read(){
  cout<<"Enter name :"<<endl;
  cin>>name;
  //cout<<"Enter account number"<<endl;
 // cin>>accNum;
  cout<<"Enter address"<<endl;
  cin>>add;
 // cout<<"Enter gender"<<endl;
  //cin>>gender;
  cout<<"Enter salary"<<endl;
  cin>>sal;
}
void person :: disp(){
    cout<<"basic datails are :"<<endl;
    cout<<endl<<"Name: "<<name<<endl<<"address"<<add<<endl;
}
int main(){
  person p2;
   person p1(15,"ABC","add1",12457);
 // p1.read();
  p1.disp();
return 0;
}
