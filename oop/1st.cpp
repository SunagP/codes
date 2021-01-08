
#include <iostream>
using namespace std;
int main() {
    
    cout << "Hello!"<<endl;
    int var1;
    char ch;
    cout<<"Enter an integer"<<endl;
    cin>>var1;
    cout<<"Enter a character"<<endl;
    cin>>ch;
    
    cout<<"Entered integer is :"<<var1<<endl;
    cout<<"Entered charater is :"<<ch<<endl;

    int x,y;
    cout<<"Enter Divident"<<endl;
    cin>>x;
    cout<<"Enter divisor"<<endl;
    cin>>y;
    if (x > y)
         cout<<"the remainder is : "<<x%y<<endl;

    else if(x<y)
        cout<<"the remainder is : "<<x<<endl;

    else 
       cout<<"remainder is : 0";


    return 0;
}