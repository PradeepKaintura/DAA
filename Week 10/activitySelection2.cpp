#include <bits/stdc++.h>

using namespace std;

bool comp(logs a,logs b){
    return a.deadline < b.deadline;
}

struct logs{
    int time;
    int deadline;
    int index;
};

int main()
{
    int n;
    cin >> n;
    vector<logs> activity(n);

    for (int i = 0; i < n; i++){
        cin >> activity[i].time;
         activity[i].index=i+1;
    }

    for (int i = 0; i < n; i++){
        cin >> activity[i].deadline;
    }

    sort(activity.begin(), activity.end(), comp);

    int lasttimer=0;
    vector<int> act;

    for (auto it : activity)
    {
        if(it.time+lasttimer <= it.deadline){
            lasttimer = it.time+lasttimer;
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
