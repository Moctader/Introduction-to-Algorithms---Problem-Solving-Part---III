#include<iostream>
#include<vector>
using namespace std;

const int n=1e5;
int visited[n];
vector<int>adj_list[n];

void Dfs(int node)
{
    cout<<node<<endl;
    visited[node]=1;
    for(int adj_node:adj_list[node])
    {
        if (visited[adj_node]==0)
        {
            Dfs(adj_node);
        }
        
    }
}

int main()
{
    int node, edge;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=0;
    Dfs(src);
    return 0;
}