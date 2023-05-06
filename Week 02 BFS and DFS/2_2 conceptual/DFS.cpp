#include<iostream>
#include<vector>
using namespace std;
const int MaxN=1000;
vector<int>adj[MaxN];
bool visited[MaxN];

void dfs(int node)
{
    cout<<node<<" ";
    visited[node]=true;
    for(auto child: adj[node])
    {
        if (!visited[child])
        {
           dfs(child);
        }
        
    }
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=1; i<=edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(int i=1; i<=nodes; i++)
    {
        cout<<i<<"-> ";
        for (auto child : adj[i])
        {
            cout<<child<<" ";
        }
        cout<<"\n";
    }

    dfs(1);
    return 0;
}