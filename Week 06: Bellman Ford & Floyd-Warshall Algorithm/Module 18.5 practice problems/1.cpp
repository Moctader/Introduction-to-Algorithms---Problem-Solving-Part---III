// Write code of Bellman-Ford Algorithm using edge-list as your graph representation.

#include<iostream>
#include<vector>
using namespace std;
const int N=1e3;
int inf=1e9;
int d[N];
vector<pair<int, int>>adjl[N];

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        d[i]=inf;
    }

    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adjl[u].push_back({v,w});
    }


    for(int i=1; i<=n-1; i++)
    {
        for(int j=1; j<n; j++)
        {
            for(auto adj_node:adjl[j])
            {
                int u=j;
                int v=adj_node.first;
                int w=adj_node.second;

                if (d[u]+w<d[v])
                {
                    d[v]=d[u]+w;
                }
                
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<d[i]<<" ";
    }

    return 0;
}