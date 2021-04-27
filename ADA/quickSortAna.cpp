#include<iostream>

using namespace std;
 int count = 0;
int pos(int a[],int l,int h){
    int i = l+1;
    int j = h;
    int pivot = a[l];
   

    while(i<=j){
        while(a[i]<pivot)
        { count++;
          i++;
        }
        while(a[j]>pivot){
          j--; 
          count ++;
        }
        count ++; 
        if(i<j)
         swap(a[i],a[j]);
    }
    // if(j<=i)
    swap(a[j],a[l]);

    return j;
    // cout << count;

}
// int pos(int arr[], int low, int high)
// {
//     int pivot = arr[high];    // pivot
//     int i = (low - 1);  // Index of smaller element
 
//     for (int j = low; j <= high- 1; j++)
//     {
//         // If current element is smaller than or
//         // equal to pivot
//         if (arr[j] <= pivot)
//         {
//             i++;    // increment index of smaller element
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

void quickSort(int a[],int l,int h){

    if(l<h){
        int p = pos(a,l,h);
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }
}

int main(){
   int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int arr[n];
    // cout<<"Enter "<<n<<" numbers\n";
    int j =n;
    for(int i=0;i<n;i++){
        
       arr[i] = rand();
    }
    cout<<"assending array is : ";
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;

    quickSort(arr,0,n-1);

    // cout<<"Sorted array is : ";
    // for(int i=0;i<n;i++){
    //     cout<< arr[i]<<" ";
    // }
    cout<<count;
    }
