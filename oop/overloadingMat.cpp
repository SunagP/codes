#include<iostream>

using namespace std;

class matr{
    int a[10][10];
    
    public:
    int m,n;
     void setDim(){
         cout<<"Enter\n";
         cin>>m>>n;
     }
    friend istream & operator >>(istream &in,matr &ma){
        
         for (int i = 0;i<ma.n;i++){
             for(int j=0;j<ma.m;j++){
                 cout<<"m["<<i<<"]["<<j<<"] :";
                 in>>ma.a[i][j];
             }

         }return in;
     }
      friend ostream & operator <<(ostream &out,matr &ma){
        
         for (int i = 0;i<ma.n;i++){
             for(int j=0;j<ma.m;j++){
                 out << ma.a[i][j]<<" ";
             }
             cout<<endl;

         }return out;
     }
};

int main(){
    matr m1;

    m1.setDim();
    cout<<"Enter matrix data\n";
    cin>>m1;
    cout<<m1;
}