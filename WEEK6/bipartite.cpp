#include<bits/stdc++.h>

using namespace std;

isBip(vector<vector<int>> graph, int n ,int src)
{
    vector<int> color(n,-1);

    color[src]=1;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(graph[u][u]==1)
            return false;

        for (int v=0;v<n;v++)
        {
            if(graph[u][v] && color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            else if(graph[u][v] && color[v]==color[u])
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> graph(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
                int t;
                cin>>t;
                graph[i].push_back(t);
        }
            
    }


    isBip(graph,n,0)?cout<<"YES": cout<<"NO";
}
