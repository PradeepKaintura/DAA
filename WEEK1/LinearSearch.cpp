#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int>v,int element,int size)
{
    for(int i=0;i<size;i++)
    {
        if(v[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int t,size;
    cin>>t;
    while(t--)
    {
        vector<int>v;
        int element=0;
        cin>>size;
        for(int i=0;i<size;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        cin>>element;
        int x = linearSearch(v,element,size);
        if(x!=-1)
        {
            cout<<"Present "<<++x;
        }
        else
        {
            cout<<"Not Present "<<element;
        }
        cout<<endl;
    }
    return 0;
}