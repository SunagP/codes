#include<iostream>

using namespace std;

void heapify(int arr[],int n,int i){
    int lar = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l<n && arr[l]>arr[lar]){
        lar = l;
    }

    if(r<n && arr[r]>arr[lar]){
        lar = r;
    }

    if(lar!=i){
        swap(arr[i],arr[lar]);
        heapify(arr,n,lar);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>1;i--){
        swap(arr[1],arr[i]);
        heapify(arr,i,1);
    }
}


int main(){
    int arr[100];
    int n;
    cout<<"Enter size of array : \n";
    cin>>n;
    
    cout<<"enter "<<n<<" numbers :\n";
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<"Entered array :\n";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    heapsort(arr,n+1);
    
    cout<<"\nsorted array :\n";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}