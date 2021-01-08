#include<iostream>
using namespace std;
class Student
{
    int marks;
    public:
        void input(int);
        int operator<(Student);
};
void Student::input(int n)
{
    cout<<"Enter the marks of student "<<n<<" :"<<endl;
    cin>>marks;
}
int Student::operator<(Student s2)
{
    if(marks<s2.marks)
        return 1;
    else if(marks>s2.marks)
        return 2;
    else
        return 0;
}
int main()
{
    Student s1,s2;
    s1.input(1);
    s2.input(2);
    int flag;
    flag=s1<s2;
    if(flag==1)
        cout<<"Marks of Student 1 is lesser than marks of Student 2."<<endl;
    else if(flag==2)
        cout<<"Marks of Student 1 is greater than marks of Student 2."<<endl;
    else
        cout<<"The marks of the students are equal"<<endl;
    return 0;
}