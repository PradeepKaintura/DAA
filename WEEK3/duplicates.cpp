#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void duplicateElements(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
        duplicateElements(arr,n);
    }
    return 0;
}