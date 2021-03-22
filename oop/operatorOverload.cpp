#include<iostream>

using namespace std;

class x{
    int a,b;
    public:
     friend ostream & operator <<(ostream &out,x &obj){
         out<<obj.a<<endl<<obj.b<<endl;
         return out;
     }
     friend istream & operator >>(istream &in,x &obj1){
         cout<<"Enter\n";
         in>>obj1.a;
         in>>obj1.b;

         return in;

     }
};
class y{
    int c,d;
    public:
     y(){
        c=10;
        d=10;
        }
    y(int n, int m)
    {
        c = n;
        d = m;
    }
   friend void operator -(y &obj){
       obj.c= -obj.c;
       obj.d = -obj.d;

    //    return obj;
    }
    void disp()
    {
        cout<<c<<endl<<d<<endl;
    }
    bool operator <(y& obj){
        if(c<obj.c)
         return true;
        return false;
    }
    y operator +(y obj){
        y temp;
        temp.c = c + obj.c;
        temp.d = d + obj.d;
        return temp;
    }
};
class array {
   private:
      int arr[5];
      
   public:
      array() {
         int i;
         for(i = 0; i < 5; i++) {
           arr[i] = i;
         }
      }
      
      int &operator[](int i) {
         if( i > 5 ) {
            cout << "Index out of bounds" <<endl; 
            // return first element.
            return arr[0];
         }
         
         return arr[i];
      }
};

int main(){
    // x X;
    // cin>>X;
    // cout<<X;
    // y Y;
    // Y.disp();
    // -Y;
    // Y.disp();

    y Y1(10,20),Y2(30,24);
    if(Y1<Y2)
     cout<<"true\n";
   else cout<<"false\n";

   y y3;
   y3 = Y1+Y2;
   y3.disp();

// array A;

//    cout << "Value of A[2] : " << A[2] <<endl;
//    cout << "Value of A[5] : " << A[5]<<endl;
//    cout << "Value of A[12] : " << A[12]<<endl;


    return 0;
}