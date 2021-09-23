#include <bits/stdc++.h>
using namespace std; 

int s=0,c=0;
void swap(int* a,int* b) {
    s++; 
    int t=*a; 
    *a=*b; 
    *b=t; 
} 

int partition (int arr[], int low, int high) { 
    int pivot=arr[high]; 
    int i=(low-1); 
    for (int j=low;j<=high-1;j++) { 
        c++;
        if (arr[j]<pivot) {
            i++; 
            swap(&arr[i],&arr[j]); 
        } 
    } 
    swap(&arr[i+1],&arr[high]); 
    return (i+1); 
} 

void quickSort(int arr[],int low,int high) { 
    if (low<high) {
        int piv = partition(arr,low,high);  
        quickSort(arr,low,piv-1); 
        quickSort(arr,piv+1,high); 
    } 
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
        quickSort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\nComparisons: "<<c<<endl;
        cout<<"Swaps: "<<s<<endl;
        s=0,c=0;
    }
    return 0;
}