#include<iostream>

using namespace std;
class mat
{
  int m,n;//rows and cols
  int **a;// pointer for 2d array
public:
 mat()
 {
   m=2;
   n=2;
   a= new int*[m];
  for(int i=0;i<m;i++)
   a[i]=new int(n);
 for(int i=0;i<m;i++)
 for(int j=0;j<n;j++)
 {
   a[i][j]=0;
  } 
 }
 mat(int r,int c)
 {
  m=r;
  n=c;
  a= new int*[m];
  for(int i=0;i<m;i++)
   a[i]=new int [n];
  for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
 {
   a[i][j]=0;
  } 
}
void read();
void display();
mat operator -(mat mat1);
friend mat operator +(mat mat1,mat mat2); 
};
void mat::read()
{
 for(int i=0;i<m;i++)
 for(int j=0;j<n;j++)
 {
   cin>>a[i][j];
  } 
}
void mat::display()
{
 for(int i=0;i<m;i++)
 {
 for(int j=0;j<n;j++)
 {
   cout<<a[i][j]<<"\t";
  }
  cout<<"\n";
  } 
}

mat mat::operator -(mat mat1)
{
  mat res(m,n);
//  res.m=m;
 // res.n=n;
  for(int i=0;i<m;i++)
 for(int j=0;j<n;j++)
 {
   res.a[i][j]=a[i][j] - mat1.a[i][j];

  } 
 return(res);
}
 mat operator +(mat a, mat b)
{
    mat c(a.m,a.n);
    
    for(int i=0; i<a.m; i++)
    {
        for(int j=0; j<a.n ; j++)
        {
            c.a[i][j] = a.a[i][j] + b.a[i][j];
        }
    }
    
    return c;
}
int main()
{
  int r,c;
  cout<<"enter the row and column\n";
  cin>>r>>c;
  mat m1(r,c);//paramertized and dynamic initializing aswell as dynamic constructor
  mat m2(r,c);
  mat m3(r,c);
  m1.display();
  m2.display();
  cout<<"enter the matrix1 elements\n";
  m1.read();
 cout<<"enter the matrix2 elements\n";
  m2.read();
  m3=m1+m2;
 cout<<" matrix are \n";
  m1.display();
 cout<<" matrix are \n";
 m2.display();
  cout<<"resultant matrix is\n";
  m3.display();
  cout<<"resultant matrix after subtraction is\n";
  m3=m1-m2;
  m3.display();
}
