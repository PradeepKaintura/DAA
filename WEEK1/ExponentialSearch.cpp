#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    int key,comp=0;
    cin >> key;

    if (arr[0]==key){
        cout<<"Found at index 0 with 0 comparisons";
        return 0;
        }

    int i;
    
    for (i = 1; i < n; i *= 2,comp++)
        if (arr[i]>=key)
            break;

    for (int j = i / 2; j <= i;j++,comp++)
        if(arr[j]==key){
            cout<<"Found at index "<< j <<" with "<<comp<<" comparisons";
            return 0;
        }

    cout<<"Not Found";

    return 0;
}