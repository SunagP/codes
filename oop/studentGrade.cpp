#include <iostream>
using namespace std;
class student{
 int m;
 public:
  void get(){
   cout<<"Enter marks"<<endl;
   cin>>m;
   }
   void disp();
   friend void predict(student);
   };
   
   void predict(student s)
   {
     if(s.m>=90 && s.m<=100)
      cout<<"s grade"<<endl;
     else if(s.m>=80)
      cout<<"A grade"<<endl;
     else if(s.m>=70)
      cout<<"B grade"<<endl;
     else if(s.m>=60)
      cout<<"C grade"<<endl;
      else if(s.m>=50)
      cout<<"D grade"<<endl;
      else if(s.m>=40)
      cout<<"E grade"<<endl;
      else if(s.m>=30)
      cout<<"F grade"<<endl;
      }
      
      
      
      int main()
      {
       student s;
       s.get();
       predict(s);
       return 0;
       }
   