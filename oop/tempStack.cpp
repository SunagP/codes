#include<iostream>

using namespace std;
#define size 3
template<class T>
class stack{
    int top;
    public:
     T arr[size];
     void pop();
     void push(T x);
     stack(){top=-1;};
};
template<class T>
void stack<T>:: pop(){
  try{
      if(top == -1){
       throw(top);
      }
      else cout<<(arr[top--]);
  }catch(int x){
    cout<<x<<"empty\n";
}
// cout<<endl<<arr[top];top--;
// return(arr[top--]);
}
template<class T>
void stack<T> :: push(T x){
    try{
 if (top==size-1)
  throw(top);
 else arr[++top] = x;cout<<"pushed";}catch( int x){
     cout<<"\nstack full\n"<<x;
 }
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(5);
    s.push(5);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
     

    

}