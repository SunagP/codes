#include <iostream>

using namespace std;
/*int main()
{
    int age;
    cout<<"Enter age\n";
    cin>>age;
    try
    {   if(age>=18)
         cout<<"your eligible\n";
        else
        {
            throw age;
        }
        
    }
    catch(int age)
    {
        cout<<"not eligible :"<<age;
    }
    
}*/
/*void check(int age)
{
    try
    {   if(age>=18)
         cout<<"your eligible\n";
        else
        {
            throw age;
        }
        
    }
    catch(int age)
    {
        cout<<"not eligible :"<<age;
    }
}
int main()
{
    int age;
    cout<<"Enter age\n";
    cin>>age;
    check(age);
    check(14);
    cout<<"\nyessss";
    return 0;

}*/
void check(int age)
{
    try
    {   if(age>=18)
         cout<<"your eligible\n";
        else
        {
            throw age;
        }
        
    }
    catch(int age)
    {
        cout<<"not eligible :"<<age;
    }
}
int main()
{
    int age;
    cout<<"Enter age\n";
    cin>>age;
    check(age);
    check(14);
    cout<<"\nyessss";
    return 0;

}