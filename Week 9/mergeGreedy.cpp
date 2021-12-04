#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int minCost=0;
    for (int i = 0; i < n-1; i++){
        minCost += (arr[i]+arr[i+1]);
        arr[i + 1] = arr[i] + arr[i + 1];
    }
    cout << minCost;
    return 0;
}
