#include<iostream>
using namespace std;

int firstOccurance(int arr[],int n,int key)
{
    int low=0,high=n-1,result=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
        {
            result=mid;
            high=mid-1;
        }
        else
        {
            if(arr[mid]>key)
                high=mid-1;
            else
                low=mid+1;
        }
    }
    return result;
}

int lastOccurance(int arr[],int n,int key)
{
    int low=0,high=n-1,result=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
        {
            result=mid;
            low=mid+1;
        }
        else
        {
            if(arr[mid]>key)
                high=mid-1;
            else
                low=mid+1;
        }
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int key;
        cin>>key;
        int x = firstOccurance(arr,n,key);
        if(x==-1)
        {
            cout<<"element not found"<<endl;
            continue;
        }
        int y = lastOccurance(arr,n,key);
        cout<<key<<" - "<<y-x+1; 
        cout<<endl;
    }
    return 0;
}