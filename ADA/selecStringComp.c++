#include<iostream>
#include<string.h>
int count=0;
using namespace std;

void strMatching(string t ,string p)
{
  int x = t.length();
  int y = p.length();
  
int flag=0;
  for(int i = 0;i<=x-y;i++)
  {   int j;
      for(j=0;j<y;j++)
      {   count++;
          if(t[i+j] == p[j])
           continue;
          else
           break;
            
      }
       
      if(j==y)
       {   
           flag++;
           cout<<"pattern found at index "<<i<<endl;
       }
       
       
  }
  if(flag==0){
      cout<<"pattern not found\n";
  }
// cout<<"count/x :"<<count/x<<endl<<"count/(x*x) : "<<count/(x*x)<<endl<<"count/y : "<<count/y<<endl<<"count/xy : "<<count/(x*y)<<endl;
}

int main()
{
 
    string x,y;
  
  
    cout<<"Enter text \n";
    getline(cin,x);
    cout<<"Enter pattern \n";
    getline(cin,y);
    strMatching(x,y);
    cout<<"\ncount value :"<<count;
    return 0;

}