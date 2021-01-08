#include<iostream>
using namespace std;
class student{
  private:
    string USN;
    int marks[6][3];

  public :
    void read();
    void calc();
    void disp();
};

void student :: read()
{ int i;
   cout<<"Enter USN :"<<endl;
   cin>>USN;
   cout<<"Enter marks in 6 subjects"<<endl;
   
       for(int j=0;j<3;j++)
       {
         cout<<"Enter test "<<j+1<< "marks"<<endl;
         for(i=0;i<6;i++)
           {
              cin>>marks[j][i];
           }
   }
}
void student :: calc()
{
  for(int)
}
void student :: disp()
{

}

int main()
{

    int n,i;
    cout<<"Enter number of students "<<endl;
    cin>>n;
    student s[n];
    for(i=0;i<n;i++)
    { cout<<"Enter student "<<i+1<<" details"<<endl;
        s[i].read();
    }
}