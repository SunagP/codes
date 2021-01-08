#include<iostream>
using namespace std;

class matrix
{
  int m[5][5];
  int row;int col;
  public:void get();
  int operator ==(matrix);
  matrix operator+(matrix);
  matrix operator-(matrix);
  void print();
  
};

int matrix::operator==(matrix m)
{
  if(row==m.row && col==m.col)
  {
    return 1;
  }
  else
   return 0;
}

void matrix::get()
{
  cout<<"enter the number of rows"<<endl;
  cin>>row;
  cout<<"enter the number of columns"<<endl;
  cin>>col;
  cout<<"enter the elements of the matrix"<<endl;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {  cout<<"m["<<i<<"]["<<j<<"] :";
       cin>>m[i][j];
    }
  }
}
void matrix::print()
{
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
       cout<<" "<<m[i][j];
    }
    cout<<endl;
  }
  }


matrix matrix::operator+(matrix am)
{
  matrix x;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      x.m[i][j]=m[i][j]+am.m[i][j];
    }
    x.row=row;
    x.col=col;
  }
  return x;
}

matrix matrix::operator-(matrix sm)
{
  matrix x;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
     x.m[i][j]=m[i][j]-sm.m[i][j];
    // m[i][j]=m[i][j]-sm.m[i][j];
    }
    x.row=row;
    x.col=col;
    //row=row;
    //col=col;
  }
  return x;
  //return *this;
}

int main()
{
  matrix m1,m2,m3,m4;
  m1.get();
  m2.get();
  if(m1==m2)
  {
    m3=m1+m2;
    m4=m1-m2;
    cout<<"Matrix 1 :"<<endl;
    m1.print();
    cout<<"Matrix 2 :"<<endl;
    m2.print();
    cout<<"Addition of matrices is"<<endl;
    m3.print();
    cout<<"subtraction of matrices is"<<endl;  
    m4.print();
  }
  else
  {
    cout<<"dimensions of the matrix do not match"<<endl;
  }
  
}