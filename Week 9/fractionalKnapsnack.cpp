#include <bits/stdc++.h>

using namespace std;

bool comp(pair<double,double> p1,pair<double,double> p2){
    double valbywt1 = (double)p1.second / (double)p1.first;
    double valbywt2 = (double)p2.second / (double)p2.first;
    return valbywt1 > valbywt2;
}

int main()
{
    int n,w;
    cin >> n;
    vector<pair<double, double>> val(n);
    for (int i = 0; i < n;i++)
        cin >> val[i].first;
    for (int i = 0; i < n;i++)
        cin >> val[i].second;
    cin >> w;
    double cost = 0;

    sort(val.begin(), val.end() ,comp);

    for (int i = 0; i < n and w>0; i++)
    {
        if(w>=val[i].first){
            cost += val[i].second;
            w -= val[i].first;
        }
        else
        {
            cout << i << "-" << w;
            cost += (double)(w*((double)val[i].second/(double)val[i].first));
            w = 0;
        }
        cout << endl;
    }

    cout << "\n Cost:" << cost;
    return 0;
}
