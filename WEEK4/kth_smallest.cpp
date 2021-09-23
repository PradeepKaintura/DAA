#include <bits/stdc++.h>
using namespace std; 

void swap(int* a,int* b) {
    int t=*a; 
    *a=*b; 
    *b=t; 
} 

int partition(int arr[],int low,int high) {
    int piv=arr[high],i=low;
    for (int j=low;j<=high-1;j++) {
        if (arr[j]<=piv) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
int kthSmallest(int arr[],int low,int high,int k) { 
    if (k>0 && k<=high-low+1) {
        int pos=partition(arr,low,high);
        if (pos-low==k-1)
            return arr[pos];
        else if (pos-low>k-1)
            return kthSmallest(arr,low,pos-1,k);
        else 
        return kthSmallest(arr,pos+1,high,k-pos+low-1);
    }
    return -1;
} 
  
int main(){
    int n,i,t,k;
    cin>>t; 
    while(t--){
        cin>>n; 
        int arr[n]; 
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>k; 
        cout<<kthSmallest(arr,0,n-1,k)<<endl;
    }
    return 0;
}