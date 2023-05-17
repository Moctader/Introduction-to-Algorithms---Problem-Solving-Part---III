#include<iostream>
#include<vector>

using namespace std;
const int N=1e5;
int visited[N];
int level[N];
vector<int>adjlist[N];

void dfs(int src)
{
    visited[src]=1;
    level[src]=1;

    for(auto adj_node: adjlist[src])
    {
        if (visited[adj_node]==0)
        {
            dfs(adj_node);
            level[adj_node]++;
        }
        
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int src;
    dfs(src);
    cout<<level;

    return 0;
}