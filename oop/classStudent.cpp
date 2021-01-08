#include<iostream>
using namespace std;
class Student
{
    private:
        string USN;
        int m[6][3];
        float avg[6];
    public:
        void read();
        void calculate();
        void print();
};
void Student::read()
{
    cout << "Enter the USN" << endl;
    cin >> USN;
    for(int i=0;i<6;i++)
    {
        cout << "Enter the marks of subject " << i+1 <<" in 3 test :" << endl;
        cin >> m[i][0] >> m[i][1] >> m[i][2];
    }
}
void Student::calculate()
{
    for(int i=0;i<6;i++)
    {
        int h1=m[i][0],h2=m[i][1],h3=m[i][2];
        for(int j=0;j<3;j++)
        {
            if(m[i][j]>=h1 && m[i][j]>h2 && m[i][j]>h3)
            {
                h1=m[i][j];
            }
            else if(m[i][j]>=h2 && m[i][j]>h3)
            {
                h2=m[i][j];
            }
            else
            {
                h3=m[i][j];
            }
        }
        avg[i]=(h1+h2)/2;
    }
}
void Student::print()
{
    cout << "USN: " << USN <<endl;
    for(int i=0;i<6;i++)
    {
        cout << "Average marks of subject " << i+1 <<": " << avg[i] << endl;
    }
}
int main()
{
    int n,i;
    cout << "Enter number of Students:" << endl;
    cin >> n;
    Student s[n];
    for(i=0;i<n;i++)
    {   cout<<"Enter details of student "<<i+1<<endl;
        s[i].read();
        
    }
    for(i=0;i<n;i++)
    {
       
        s[i].calculate();
        
    }for(i=0;i<n;i++)
    {   cout<<endl;
         cout<<"Student "<<i+1<<" details"<<endl;
        
        s[i].print();
        
    }
    return 0;
}