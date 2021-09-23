#include <iostream>
using namespace std;
int c=0;

int merge(int arr[],int l, int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l,inv=0;
    while(i<n1 && j<n2){
        c++;
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
            inv+=(n1-i);
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
    return inv;
}

int mergeSort(int arr[],int l,int r){
    if(l>=r) return 0;
    int mid=l+(r-l)/2;
    int inv=0;
    inv+=mergeSort(arr,l,mid);
    inv+=mergeSort(arr,mid+1,r);
    inv+=merge(arr,l,mid,r);
    return inv;
}

int main(){
    int n,i,t;
    cin>>t; 
    while(t--){
        cin>>n; 
        int arr[n]; 
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        int inv=mergeSort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\nComparisons: "<<c<<endl;
        cout<<"Inversions: "<<inv<<endl;
        c=0;
    }
    return 0;
}