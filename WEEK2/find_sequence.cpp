#include<iostream>
using namespace std;

void function1(int arr[],int n)
{
    int flag=-1;
    int sum=0;
    for(int i=0;i<n-2;++i)
    {
        for(int j=i+1;j<n-1;++j)
        {
            sum=arr[i]+arr[j];
            for(int k=j+1;k<n;++k)
            {
                if(sum==arr[k])
                {
                    flag=1;
                    cout<<++i<<" "<<++j<<" "<<++k<<endl;
                }
            }
        }
    }
    if(flag==-1)
        cout<<"No sequence found";
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
        function1(arr,n);
        cout<<endl;
    }
}