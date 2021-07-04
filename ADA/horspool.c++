#include<iostream>
#include<string.h>
using namespace std;

int horspool(string t,string p){
    int n =t.length();
    int m = p.length();

    int table[130];

    for (int i=0;i<126;i++){
        table[i] = m;

    }
    for(int j=0;j<=m-2;j++){
        table[p[j]] = m-1-j;
    }

    int i = m-1;
    while(i<=n-1){
    int k = 0;
    while(k<=m-1 && p[m-1-k]==t[i-k])
    {
        k++;

    }
    if(k==m)
     return i-m+1;
    else 
     i = i+table[t[i]];
    }
    return -1;
}


int main(){
    cout<<"Enter text : \n";
    string t;
    // cin>>t;
    getline(cin,t);
    cout<<"Enter pattern :\n";
    string p;
    // cin>>p;
    getline(cin,p);
    int x = horspool(t,p);

    if(x>=0)
     cout<<"Pattern found at index "<<x<<endl;
    else
     cout<<"Pattern not found\n";
}