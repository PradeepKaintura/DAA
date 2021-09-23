#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void jumpSearch(vector<int>&v,int size,int search)
{
    int count=0;
    int low=0,high=sqrt(size);
    while(v[high]<=search && high<size)
    {
        count+=1;
        low=high;
        high+=sqrt(size);
        if(high>size-1)
        {
            high=size;
        }
    }
    for(int i=low;i<high;i++)
    {
        count+=1;
        if(v[i]==search)
        {
            cout<<"Found "<<count<<endl;
            return;
        }
    }
    cout<<"Not Present "<<count<<endl;
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    vector<int>v;
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int search;
    cin>>search;
    jumpSearch(v,size,search);
    }
    return 0;
}