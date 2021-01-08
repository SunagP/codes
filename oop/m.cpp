#include<iostream>
using namespace std;
class matrix
{
        int r,c,a[20][20];
        public : void read();
                 void display();
                 matrix operator+(matrix);
                 matrix operator-(matrix);
                 int operator==(matrix);
};
void matrix::read()
{
        cout<<"enter number of rows : ";
        cin>>r;
        cout<<"enter number of columns : ";
        cin>>c;
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        cout<<"enter element of row "<<i+1<<"and column "<<j+1<<endl;
                     cin>>a[i][j];
                }
        }
}
void matrix::display()
{
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        cout<<" "<<a[i][j]<<" ";
                }
                cout<<"\n";
        }
}
int matrix:: operator==(matrix m)
{
        if(r==m.r&&c==m.c)
        {
                return 1;
        }
        return 0;
}
matrix matrix::operator+(matrix m2)
{
        matrix x;
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        x.a[i][j]=a[i][j]+m2.a[i][j];
                }
        }
        return x;
}
matrix matrix::operator-(matrix m2)
{
        matrix x;
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        x.a[i][j]=a[i][j]-m2.a[i][j];
                }
       }
        return x;
}
int main()
{
        matrix m1,m2,m3,m4;
        m1.read();
        m2.read();
        if(m1==m2)
        {
                m3=m1+m2;
                m4=m1-m2;
        }
        else
        {
                cout<<"order of matrices does not match\n"<<endl;
        }
        m1.display();
        m2.display();
        m3.display();
        m4.display();
return 0;
}