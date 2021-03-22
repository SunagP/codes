//  /* Program to convert basic type to class type using constructor */

#include <iostream>
using namespace std;
class Time
{
	int hrs,min;
	public:
        //  Time(int);
         void operator=(int t){
           hrs = t/60;
           min = t%60;
        
         }  
        //  Time(int x,int y){
        //      min = x;
        //      hrs = y;
        //  }   
        //  operator int(){
        //    return(hrs*60+min);
        //  }
		 void display();
};

// Time :: Time(int t)
// {
// 	cout<<"Basic Type to ==> Class Type Conversion..."<<endl;
// 	hrs=t/60;
// 	min=t%60;
// }

void Time::display()
{
	cout<<hrs<< ": Hour(s)" <<endl;
	cout<<min<< " Minutes" <<endl;
}
int main()
{
	
	
	int duration;
	cout<<"Enter time duration in minutes"; 
        cin>>duration;
	Time t;
    t = duration;
	// Time t1=(duration);
    //  Time  t2(5,5);
    //  t2 = duration;
	// t2.display();
    // int total = t2;
    // cout<<total;
	return 0;
}
