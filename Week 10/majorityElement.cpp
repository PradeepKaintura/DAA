#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i:arr)
        cin >> i;
    int majority = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++){
        if(count==0){
            majority = arr[i];
            count++;
        }else{
            if(arr[i]==majority)
                count++;
            else
                count--;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++){
        if(arr[i]==majority)
            count++;
    }

    if(count>n/2)
        cout << "Yes\n";
    else
        cout << "No\n";

    sort(arr.begin(), arr.end());

    if(n&1){
        cout<< arr[n/2]<<endl;
    }
    else{
        int n1=n/2;
        int n2=n1-1;
        int ans=arr[n1]+arr[n2];
        cout<<ans/2<<endl;
    }

    return 0;
}
