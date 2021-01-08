#include<iostream>
using namespace std;
class date
{
  int m,y,d;
  public:void read();
         void display();
         void operator++();
};
void date::operator++()
{
  int x=1;
  while(x){
  cout<<"Enter your choice to increment"<<endl;
 cout<<"1 year"<<endl<<"2 month"<<endl<<"3 date"<<endl<<"0 exit"<<endl; 
 cin>>x;
 switch(x)
     {
      case 1: y++;
      break;
     case 2: if(m>=12)
  {
           y++;
  }
            else
          {
              m++;
          }
      break;
     case 3: if(d>=31)
 {
       m++;
 }
             else
              {
                   d++;
              }

             break;
   /*default :cout<<"invalid\n"<<endl;
   break;*/
        }
}
}
void date::read()
{
        cout<<"Enter the date in dd mm yyyy format"<<endl;
        cin>>d>>m>>y;
}
void date::display()
{ cout<<"After updating new date is : "<<endl;
  cout<<""<<d<<" "<<m<<" "<<y<<endl;
}
int main()
{
        date d1;
        d1.read();
        ++d1;
        d1.display();
        return 0;
}
