#include<iostream>
#include<string.h>
using namespace std;

class str{
    char s[10];
    public:
    void getstr(){
        cout<<"\nenter string\n";
        cin>>s;
    }
    str operator +(str a){
        // str temp;
        // strcpy(s,s);
        strcat(s,a.s);
        return *this;

    }
    bool operator ==(str a){
        str temp;
        strcpy(temp.s,s);
        if(strcmp(temp.s,a.s)==0)
         return true;
        else return false;
    }

    void disp(){
        cout<<s;
    }
};

int main()
{
    str s1,s2,s3;
    s1.getstr();
    s2.getstr();

    s3 = s1+s2;
    s3.disp();
    if(s1==s2)
     cout<<"\nsame string\n";
    else cout<<"\nDiff string";
    return 0;
}