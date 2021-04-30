#include<iostream>
using namespace std;
int count = 0;
void selection_sort(int *a ,int n){
    
    for(int i=0; i<n-1; i++)
    { int m =i;
        for (int j=i+1; j<n; j++){
         count++;
         if(a[j]<a[m])
          m = j;
        }
       
        swap(a[i],a[m]);

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
    cout<<"\ncount value :"<<count;

}