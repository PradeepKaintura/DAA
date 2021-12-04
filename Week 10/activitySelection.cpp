#include <bits/stdc++.h>

using namespace std;

struct logs{
    int start;
    int end;
    int index;
};

bool comp(logs a,logs b){
    return a.end < b.end;
}

int main()
{
    int n;
    cin >> n;
    vector<logs> activity(n);

    for (int i = 0; i < n; i++){
        cin >> activity[i].start;
        activity[i].index = i + 1;
    }

    for (int i = 0; i < n; i++){
        cin >> activity[i].end;
    }

    sort(activity.begin(), activity.end(), comp);

    int lastEnd=-1;
    vector<int> act;

    for (auto it : activity)
    {
        if(it.start >=lastEnd){
            lastEnd = it.end;
            act.push_back(it.index);
        }
    }

    cout << "No. of non conflicting activities: " << act.size();
    cout << "\nList of selected activities: ";
    for (auto it : act){
        cout << it << ", ";
    }
        return 0;
}
