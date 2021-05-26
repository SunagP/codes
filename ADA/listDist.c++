#include<iostream>
using namespace std;

void distinct(int arr[],int n){
    int count=-1;
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                // cout<<"array is not distinct\n";
                
            }break;
        }
    }
    if(count>0){
        cout<<"array is not distinct\n";
        for(int i=0;i<n;i++){
        int j;
        for(j=0;j<n;j++){
            if(arr[i]==arr[j]){
                arr[i] = arr[i]+arr[i-1];
            }
        }
    }
    }
    else{
        cout<<"distinct";
    }
    
    cout<<"Distinct array :\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     
    }
    


}

int main(){
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements\n";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    distinct(a,n);
    return 0;
}