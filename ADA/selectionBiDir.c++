#include<iostream>
using namespace std;
void selectSortBiDir(int *a,int n)
{
    int i=0,j=0,min ,last=n-1,max;
    for ( i = 0; i<last ; i++)
    {
        max=i;
        min=i;
        for (j = i+1; j <=last; j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            if(a[j]>a[max])
            {
                max=j;
            }
        }
        if(max==i)
        {
            swap(a[min],a[i]);
            max=min;
            swap(a[max],a[last]);
        }
        else if(min==last)
        {
            swap(a[max],a[last]);
            min=max;
            swap(a[min],a[i]);
           
        }
        else
        {
            swap(a[min],a[i]);
            swap(a[max],a[last]);
        }
        last--;

    }
    
}
int main()
{
    int n=0;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter element "<<i+1<<":"<<endl;
        cin>>a[i];
    }
    cout<<"before sort :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" "<<endl;
    }
    selectSortBiDir(a,n);
    cout<<"after sort :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" "<<endl;
    }
    
    
}