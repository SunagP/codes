#include<iostream>
using namespace std;
int top=-1,Max=5;
int stack[5];
class st
{
    public:
    void push()
    {  cout<<"Enter data"<<endl;
        
       cin>>stack[++top];
    }
    void pop()
    {   
        cout<<stack[top--];
    }
};

class child :public st
{   public:
    void push()
    {
        if(top==Max-1)
         cout<<"Over flow";
        else
        {
            return st ::push();
        }
        
         
    }
    void pop()
    {
        if(top==-1)
        cout<<"under flow\n";
        else
        {
            return st::pop();
        }
        
    }
};


int main()
{
    child c;
    c.pop();
    c.push();

    c.pop();

}