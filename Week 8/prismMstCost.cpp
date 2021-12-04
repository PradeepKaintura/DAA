#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cout << "Enter num of cities";
    cin >> N;
    int  c;
    vector<vector<int>> graph(N,vector<int>(N,INT_MAX));
    cout << "\nEnter roads matrix with cost:\n";

    for (int i = 0; i < N; i++)
    for (int j = 0;j < N;j++)
    {
        cin >> c;
        graph[i][j] = (c==0)?INT_MAX:c;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(N, INT_MAX);
    vector<int> mst(N, 0);
    vector<int> parent(N, -1);

    mst[0] = 1;
    key[0] = 0;
    pq.push({0, 0});

    for (int i = 0; i < N-1; i++)
    {
        int par = pq.top().first;
        pq.pop();
        mst[par] = 1;

        for (int it = 0; it < graph[par].size();it++)
        {
            if(graph[par][it]!=INT_MAX){
                int child = it;
                int weight = graph[par][it];
                if(mst[child]==0 && weight<key[child]){
                    key[child] = weight;
                    parent[child] = par;
                    pq.push({child, weight});
            }}
        }
    }

    int cost=0;
    cout << "\nEdges:";
    for (int i = 1; i < parent.size(); i++)
    {
        cout << "\n" << i<< " - "<<  parent[i] ;
        cost += key[i];
    }
    cout << "Minimum Cost: "<<cost;

    return 0;
}
