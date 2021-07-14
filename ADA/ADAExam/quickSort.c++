#include<iostream>

using namespace std;

int pos(int a[],int l ,int h){

    int  i = l+1;
    int j = h;

    int pivot = a[l];

    while(i<=j)
    {
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[j],a[l]);

    return j;
}

int posL(int a[],int l ,int h){

    int  i = l;
    int j = h-1;

    int pivot = a[h];

    while(i<=j)
    {
        while(a[i]<=pivot){
            // count++
            i++;
        }
        while(a[j]>pivot){
            // count++;
            j--;
        }
        // count++;
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[i],a[h]);

    return i;
}
int posM(int a[],int l ,int h){

    int  i = l;
    int j = h-1;
    int mid = (l+h)/2;
    int pivot = a[mid];

    while(i<=j)
    {
        while(a[i]<=pivot){
            // count++
            i++;
        }
        while(a[j]>pivot){
            // count++;
            j--;
        }
        // count++;
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    // swap(a[i],a[h]);

    return i;
}
// void quickSortm(int a[],int l,int h){


// if(l<h){
//     // int p = posM(a,l,h);
//     int mid = (l+h)/2;
//     int pivot = a[mid];
//     int i=l,j=h;
//     while(i<j){
//         // count++;
//         if(a[i]>=pivot && a[j]<=pivot){
//             swap(a[i],a[j]);
//             i++;
//             j--;
//         }
//         else{
//             i++;
//         }
//     }
//     quickSort(a,l,mid);
//     quickSort(a,mid+1,h);
// }
// }

void quickSort(int a[],int l,int h){


if(l<h){
    int p = posM(a,l,h);
    quickSort(a,l,p-1);
    quickSort(a,p+1,h);
}
}

int main()
{
    int n;

    cout<<"Enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements\n";

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Entered elements are \n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    quickSort(a,0,n-1);

    cout<<"Sorted array \n";

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}