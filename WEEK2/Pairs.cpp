#include<iostream>
using namespace std;

int countPairs(int arr[],int n,int key)
{
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(arr[i]-arr[j])==key)
                count++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int key;
        cin>>key;
        cout<<countPairs(arr,n,key)<<endl;
    }
    return 0;
}