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
        int x;
        cout<<"enter 1,2,3 to increment year date and month respectively"<<endl;
        cin>>x;
        switch(x)
        {
                case 1: y++;
                        break;
                case 2: if(m>=12)
                        {
                                cout<<"month number cant be greater than 12"<<endl;
                        }
                        else
                        {
                                m++;
                        }
                        break;
case 3: if(d>=31)
                        {
                                cout<<"date cant be greater than 31"<<endl;
                        }
                        else
                        {
                                d++;
                        }

                        break;
                default :cout<<"invalid\n"<<endl;
                         break;
        }
}
void date::read()
{
        cout<<"enter year month date respectively"<<endl;
        cin>>y>>m>>d;
}
void date::display()
{
        cout<<"year--"<<y<<"month--"<<m<<"date--"<<d<<endl;
}
int main()
{
        date d1;
        d1.read();
      ++d1;
        d1.display();
        return 0;
}
