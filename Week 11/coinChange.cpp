#include <bits/stdc++.h>

using namespace std;

int ways(vector<int> &arr, int i, int N,vector<vector<int>> &dp)
{
    if(N==0)
        return 1;
    if(i==arr.size())
        return 0;

    if(dp[i][N])
        return dp[i][N];

    if (N >= arr[i])
    {
        dp[i][N - arr[i]] = ways(arr, i, N - arr[i],dp);
        dp[i+1][N] = ways(arr, i + 1, N,dp);
        return dp[i][N - arr[i]] + dp[i + 1][N];
    }
    return 0;
}

int main()
{
    int n,target;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    cin >> target;
    sort(arr.begin(), arr.end());
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    cout << ways(arr, 0, target, dp)<<" ways.";
    return 0;
}
