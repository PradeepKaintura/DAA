#include <bits/stdc++.h>

using namespace std;

void mergeArr(int arr[], int l, int s, int h)
{
    int n = h - l + 1, temp[n], i = l, j = s + 1, k = 0, noi = 0;
    while (i <= s && j <= h)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
        }
    }
    for (; i <= s; ++i, ++k)
        temp[k] = arr[i];
    for (; j <= h; ++j, ++k)
        temp[k] = arr[j];
    for (int i = l, j = 0; i <= h; ++i, j++)
        arr[i] = temp[j];
}

void mergeSort(int arr[], int l, int h)
{
    int noc = 0;
    if (l < h)
    {
        int splitInd = (l + h) / 2;
        mergeSort(arr, l, splitInd);
        mergeSort(arr, splitInd + 1, h);
        mergeArr(arr, l, splitInd, h);
    }
}

void findPair(int arr[], int l, int h, int k)
{
    int flag = 1;
    while (l <= h)
    {
        if (arr[l] + arr[h] > k)
            h--;
        else
        {
            if (arr[l] + arr[h] == k)
            {
                cout << arr[l] << " " << arr[h] << ", ";
                flag = 0;
            }
            l++;
        }
    }
    if (flag)
        cout << "No such pair exist";
    cout << endl;
}

int main()
{

    int no;
    cin >> no;
    for (int f = 0; f < no; f++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int key;
        cin >> key;
        mergeSort(arr, 0, n - 1);
        findPair(arr, 0, n - 1, key);
    }
    return 0;
}