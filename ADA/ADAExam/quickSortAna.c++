#include<iostream>
#include<math.h>

using namespace std;
int count = 0;
int pos(int a[],int l ,int h){

    int  i = l+1;
    int j = h;

    int pivot = a[l];

    while(i<=j)
    {
        while(a[i]<=pivot){
            count++;
            i++;
        }
        while(a[j]>pivot){
            count++;
            j--;
        }
        count++;
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[j],a[l]);

    return j;
}


void quickSort(int a[],int l,int h){


if(l<h){
    int p = pos(a,l,h);
    quickSort(a,l,p-1);
    quickSort(a,p+1,h);
}
}

int main()
{
    int n;

    cout<<"Enter number of elements\n";
    cin>>n;
    int a[n],d[n],r[n];
    // cout<<"Enter "<<n<<" elements\n";
    cout<<"Ascending input\n";
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    // cout<<"descending input\n";
    // for(int i=0;i<n;i++){
    //     d[i]=n-i;
    // }
    // cout<<"Random input\n";
    // for(int i=0;i<n;i++){
    //     r[i]=rand();
    // }

    // cout<<"Entered elements are \n";
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    quickSort(a,0,n-1);
    // quickSort(d,0,n-1);
    // quickSort(r,0,n-1);

    // cout<<"Sorted array \n";

    // for(int i=0;i<n;i++){
    //     cout<<r[i]<<" ";
    // }
    cout<<"\ncount : "<<count<<endl;
    cout<<"count/n : "<<(count)/(float)n<<"\ncount/(n*n) : "<<(float)count/(n*n)<<"\ncount/(nlogn) : "<<count/(n*log(n));
    return 0;
}