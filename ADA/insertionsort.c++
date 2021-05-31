#include<iostream>
using namespace std;

int binarysearch(int a[],int key,int l,int h){

    if(l<=h){
        int m = l+(h-l)/2;
    if(key==a[m])
        return m;
    if(key>a[m]){
        return binarysearch(a,key,m+1,h);
    }
    else{
        return binarysearch(a,key,l,m-1);   
    }
}

}

void binaryInsertSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key = a[i];

        int pos = binarysearch(a,key,0,j);

        while(j>=pos){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" numbers\n";
    for(int i=0;i<n;i++){
      cin>>a[i];
    }

    cout<<"Entered array :\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    binaryInsertSort(a,n);
    cout<<"\nSorted array :\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

     return 0;
}