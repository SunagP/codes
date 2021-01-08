#include <iostream>
using namespace std;
class matrix
{
  int m[3][3];
  public:
  void get();
  void display();
  
  friend matrix transpose(matrix);
};
void matrix:: get()
  { cout<<"Enter matrix elements:"<<endl;
    int i,j;
    for(i=0;i<3;i++)
    { 
      for(j=0;j<3;j++)
      { cout<<"m["<<i<<"]["<<j<<"]"<<endl;
        cin>>m[i][j];
      }
    }
  }
  void matrix:: display()
  {
    int i,j;
    //cout<<"Entered matrix is:"<<endl;
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        cout<<m[i][j]<<" ";
      }cout<<endl;
    }
  }
matrix transpose(matrix m1)
{
  matrix temp;
  int i,j;
  cout<<"Transpose of the given matrix is :"<<endl;
   for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        temp.m[i][j]=m1.m[j][i];
      }
    }
  return temp;
}
int main() {
matrix m1,m2;
m1.get();
cout<<"Entered matrix is:"<<endl;
m1.display();
cout<<endl; 
m2=transpose(m1);

m2.display();
}