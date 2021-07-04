#include<iostream>
using namespace std;

void selection_sort(int *a ,int n){
    int count=0;
    for(int i=0; i<n-1; i++)
    { int m =i;
        for (int j=i+1; j<n; j++){
        count++; 
         if(a[j]<a[m])
          m = j;
        }
        
        swap(a[i],a[m]);

    }
    cout<<"\n"<<count<<"\n";
}

int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int arrA[n],arrD[n],arrR[n];
    cout<<"Assending array\n";
    for(int i=0;i<n;i++){
        arrA[i] = i;
    }
    cout<<"descending array\n";
    for(int i=n;i<0;i--){
        arrA[i] = i;
    }
    cout<<"random array array\n";
    for(int i=n;i<0;i--){
        arrA[i] = rand();
    }
    cout<<"Entered array is : ";
    for(int i=0;i<n;i++){
        cout<< arrA[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<< arrD[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<< arrR[i]<<" ";
    }
    cout<<endl;


    selection_sort(arrA,n);
    cout<<"Sorted array assending arary is : ";
    for(int i=0;i<n;i++){
        cout<< arrA[i]<<" ";
    }
    cout<<endl;
    selection_sort(arrD,n);
    cout<<"Sorted array descending arary is : ";
    for(int i=0;i<n;i++){
        cout<< arrD[i]<<" ";
    }
    cout<<endl;
    selection_sort(arrR,n);
    cout<<"Sorted array descenting arary is : ";
    for(int i=0;i<n;i++){
        cout<< arrR[i]<<" ";
    }
    cout<<endl;

}