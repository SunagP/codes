#include<iostream>
using namespace std;
class Employee
{
    private:
        int empNo;
        string empName;
        float basic,da,it,net;
    public:
        void read();
        void calculate();
        void print();
        
};
void Employee::read()
{
    cout << "Enter Employee Number:" <<endl;
    cin >> empNo;
    cout << "Enter Employee Name:" <<endl;
    cin >> empName;
    cout << "Enter Basic salary:" <<endl;
    cin >> basic;
}
void Employee::calculate()
{
    da=basic*0.52;
    it=(basic+da)*0.30;
    net=basic+da-it;
}
void Employee::print()
{
    cout << "Employee No: " << empNo << endl;
    cout << "Employee Name: " << empName << endl;
    cout << "Employee Net Salary: " << net << endl;
}
int main()
{  
    int n,i;
    cout << "Enter number of Employees:" << endl;
    cin >> n;
    Employee e[n];
    for(i=0;i<n;i++)
    {   cout<<"Enter employee "<<i+1<<" details :"<<endl;
        e[i].read();
        e[i].calculate();
       
    }
    for(i=0;i<n;i++)

    {  cout<<endl;
          cout<<"employee "<<i+1<<" details :"<<endl;
         e[i].print();
    }
    return 0;
}