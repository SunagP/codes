#include<iostream>

using namespace std;

template<class T>
T largest(T a[],int n,T large){
    for (int i=0;i<n;i++)
     {
        if(a[i]>=large)
         large = a[i];
     }
    return large;
}


int main()
{
    float a[5] = {1.1,5,0,2.5,6.5};
    float large = a[0];
    float x = largest<float>(a,5,large);
    cout<<x;
}