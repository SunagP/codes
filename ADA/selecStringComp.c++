#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void strMatching(string t ,string p)
{
  int x = t.length();
  int y = p.length();
  int count=0;
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
  char text[200];
  ofstream file1;
  file1.open ("pattern.txt");

  cout << "Write text to be written on file." << endl;
  
  cin.getline(text, sizeof(text));
  file1.close();
  ifstream file2;
  file2.open ("pattern.txt");
  file2 >> text;
  // cout << text << endl;
    // cout<<"Enter text \n";
    // getline(cin,x);
    cout<<"Enter pattern \n";
    getline(cin,y);
    strMatching(text,y);
    
    return 0;

}