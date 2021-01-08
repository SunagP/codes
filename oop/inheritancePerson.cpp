#include<iostream>
using namespace std;

class person{

    public:
    string name,age,city;
    void get();
    void disp();

};
class faculty : public person
{
    public:
    string sub;
    void read();
    void print();
    string designation;
};
class nonteaching : public person
{   public:
    void read();
    void print();
    string designation;
};
class officestaff : public person
{   public:
    void read();
    void print();
    string designation;
};
void person :: get()
{
    cout<<"Enter name :"<<endl;
    cin>>name;
    cout<<"Enter age :"<<endl;
    cin>>age;
    cout<<"Enter city :"<<endl;
    cin>>city;
}
void faculty :: read()
{
     cout<<"Enter designation :"<<endl;
     cin>>designation;
     cout<<"Enter subjects taught"<<endl;
     cin>>sub;
}
void nonteaching :: read()
{
     cout<<"Enter designation :"<<endl;
     cin>>designation;
}
void officestaff :: read()
{
     cout<<"Enter designation :"<<endl;
    cin>>designation;
}
void person:: disp()
{
    cout<<"Enter  :"<<name<<endl;
    
    cout<<"Age :"<<age<<endl;
    
    cout<<"City :"<<city<<endl;
    
}
void faculty :: print()
{    
     cout<<"Designation :"<<designation<<endl;
     cout<<"Subjects taught"<<sub<<endl;
    
}
void nonteaching :: print()
{
     cout<<"Designation :"<<designation<<endl;
}
void officestaff :: print()
{
     cout<<"Designation :"<<designation<<endl;
}

int main()
{
    officestaff s1;
    nonteaching t1;
    faculty f1;
    cout<<"Enter Faculty details :"<<endl;
    f1.get();
    f1.read();
    cout<<"Enter officeStaff details :"<<endl;
    s1.get();
    s1.read();
    cout<<"Enter non-teaching  details :"<<endl;
    t1.get();
    t1.read();
    cout<<endl;
    cout<<"Displaying faculty details:"<<endl;
    f1.disp();
    f1.print();
    cout<<endl;
    cout<<"Displaying office staff details:"<<endl;
    s1.disp();
    s1.print();
    cout<<endl;
    cout<<"Displaying non-teaching staff details:"<<endl;
    t1.disp();
    t1.print();

}