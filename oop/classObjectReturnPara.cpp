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
     void display();
     //person addSal(person,person);
     person addSal(person);

};

/*person person :: addSal( person p2,person p1)
{
  // cout<<"salaries are : "<<p1.sal + p2.sal<<endl ;
 //  return (p1.sal + p2.sal);
 //person temp;
 //temp=p1.sal+p2.sal;
 sal=p1.sal+p2.sal;
 
 //this->sal = sal;
 return *this;
 //return temp;
}*/
/*person person :: addSal( person p2,person p1)
{
   cout<<endl<<" total salary is : "<<p1.sal + p2.sal<<endl ;
 
}*/
/*person person :: addSal( person p2,person p1)
{
  person temp;
  
 temp = p1.sal + p2.sal;
 
 
 
 return temp;
}*/
/*person person :: addSal( person p2,person p1)
{
  // cout<<"salaries are : "<<p1.sal + p2.sal<<endl ;
 //  return (p1.sal + p2.sal);
 person temp;
 //temp=p1.sal+p2.sal;
 temp.sal=p1.sal+p2.sal;
 
 //this->sal = sal;
 return temp;
 //return temp;
}*/
void person :: read(){
  cout<<"Enter name :"<<endl;
  cin>>name;
  cout<<"Enter account number"<<endl;
  cin>>accNum;
  cout<<"Enter address"<<endl;
  cin>>add;
  
  cout<<"Enter salary"<<endl;
  cin>>sal;
} 
void person :: disp(){
  
    cout<<endl<<"Name: "<<name<<endl<<"account number :"<<accNum<<endl<<"address :"<<add<<endl;
    cout<<"salary : "<<sal<<endl;
}
person person :: addSal( person p)

{
  
 person temp;
 
 temp.sal=sal+p.sal;
 
 
 return temp;
 
}
void person :: display(){
  cout<<endl;
  cout<<"Total salary is :"<<sal<<endl;

}
int main(){
  
  person p1,p2;
  p1.read();
  
  p2.read();
  p1.disp();
  p2.disp();
  person temp;
  //temp=p1.addSal(p2);
  //cout<< temp;
 //temp= temp.addSal(p1,p2);
 //temp.display();
 //temp=p1.addSal(p1,p2);
 temp=p1.addSal(p2);
temp.display();
  
}
