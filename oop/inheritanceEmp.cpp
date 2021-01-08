#include<iostream>
using namespace std;
class employee
{
    public:string name;
           int age,salary;
};
class salesPerson : public employee
{
    public:string city;
             
};
class fullTime : public salesPerson
{
    public : int Whrs;
             float bonus;
             void read();
             void display();
};
class partTime : public salesPerson
{
    public : int Whrs;
             float bonus;
             void get();
             void show();
};
void fullTime :: read()
{
    cout<<"enter \nname\nage\nsalary\ncity\nWorking hrs\nbonus recieved\n";
    cin>>name>>age>>salary>>city>>Whrs>>bonus;
}
void partTime :: get()
{
     cout<<"enter \nname\nage\nsalary\ncity\nWorking hrs\nbonus recieved\n";
    cin>>name>>age>>salary>>city>>Whrs>>bonus;
}
void fullTime::display()
{
     cout<<"name-"<<name<<"\nage-"<<age<<"\ncity-"<<city<<"\nsalary-"<<salary<<"\nworking hours-"<<Whrs<<"\nbonus-"<<bonus<<endl;
}
void partTime::show()
{
    cout<<"name-"<<name<<"\nage-"<<age<<"\ncity-"<<city<<"\nsalary-"<<salary<<"\nworking hours-"<<Whrs<<"\nbonus-"<<bonus<<endl;
}
int main()
{
    fullTime e1;
    partTime e2;
    cout<<"Enter details of full-time employee\n";
    e1.read();
    cout<<"Enter details of part-time employee\n";
    e2.get();
    cout<<"Details of full-time employee\n";
    e1.display();
    cout<<"Details of part-time employee\n";
    e2.show();
    return 0;
}