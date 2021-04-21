#include<iostream>
using namespace std;

void selection_sort(int *a ,int n){
    
    for(int i=0; i<n-1; i++)
    { int m =i;
        for (int j=i+1; j<n; j++){
         if(a[j]>a[m])
          m = j;
        }
        swap(a[n-1],a[m]);
        n--;

    }
}

int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" numbers\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Entered array is : ";
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;

    selection_sort(arr,n);
    cout<<"Sorted array is : ";
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }

}