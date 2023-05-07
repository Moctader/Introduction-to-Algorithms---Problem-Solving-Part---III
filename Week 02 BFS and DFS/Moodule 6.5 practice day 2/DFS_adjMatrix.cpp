#include<iostream>
#include<vector>
using namespace std;

const int MaxN=1000;
int graph[MaxN][MaxN]={};
bool visited[MaxN];

void dfs(int start, int n)
{
    cout<<start<<" ";
    visited[start]=true;
    for(int i=0; i<n; i++)
    {
        if (graph[start][i]==1 && !visited[start])
        {
            dfs(i, n);
        }
        
    }
}

int main()
{
    int edges, nodes;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=graph[v][u]=1;

        
    }
    // for(int i=0; i<edges; i++)
    // {
    //     for(int j=0; j<edges; j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(0, nodes);
    return 0;
}