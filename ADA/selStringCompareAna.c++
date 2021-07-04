#include<iostream>
using namespace std;
long int count=0;
void match(char *text,char *pattern,int n,int m)
{
    int i,a=0;
    for (i = 0; i < n-m+1; i++)
    {
        if(pattern[0]==text[i])
        {
            int j=0;
            while(j<m)
            {
                count++;
                if(text[i+j]==pattern[j])
                {
                    j++;
                }
                else
                {
                    break;
                }   
            }
            if(j==m)
            {
                cout<<"search successful pattern found at index "<<i<<endl;
                a=1;
                break;
            }
        }
    }
    if(a==0)
    {
        cout<<"\npattern not present in text\n"<<endl;
    }
    // cout<<count<<endl;
    
}
int main()
{
    char *text,*pattern;
    int n=10;
    int m=5;
    text=new char[n];
    pattern=new char[m];
    for (int i = 0; i < n; i++)
    {
        text[i]='0';
    }
    for (int i = 0; i < m-1; i++)
    {
        pattern[i]='0';
    }
    // pattern[m-1]='1';
    for (int i = 0; i < n; i++)
    {
        cout<<text[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
       cout<<pattern[i]<<" ";
    }
    
    
    // cout<<"enter the text :"<<endl;
    // getline(cin,text);
    // cout<<"enter the pattern to be matched :"<<endl;
    // getline(cin,pattern);
    // int n=text.length();
    // int m=pattern.length();
    match(text,pattern,n,m);
    // cout<<count<<endl;
    cout<<n<<"\n"<<m<<"\n"<<"n^2--"<<(float)count/(n*n)<<"\nm^2--"<<(float)count/(m*m)<<"\nnm--"<<(float)count/(m*n)<<endl;;
    cout<<"\nm+n--"<<(float)count/(m+n)<<endl;
    cout<<"\nn--"<<(float)count/(n);
    cout<<"\nm--"<<(float)count/(m);
    return 0;
}