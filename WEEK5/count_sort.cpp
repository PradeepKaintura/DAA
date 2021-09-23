#include <bits/stdc++.h>

using namespace std;

int main()
{

    int no;
    cin >> no;
    for (int f = 0; f < no; f++)
    {
        int n;
        cin >> n;
        int arr[26] = {0};
        for (int i = 0; i < n; ++i)
        {
            char x;
            cin >> x;
            arr[x - 'a']++;
        }
        int ind = -1, max = INT_MIN;
        for (int i = 0; i < 26; ++i)
        {
            if (arr[i] != 0 && arr[i] != 1 && arr[i] > max)
            {
                ind = i;
                max = arr[i];
            }
        }
        if (ind >= 0)
            cout << char('a' + ind) << " - " << arr[ind] << endl;
        else
            cout << "No Duplicates Present" << endl;
    }
    return 0;
}