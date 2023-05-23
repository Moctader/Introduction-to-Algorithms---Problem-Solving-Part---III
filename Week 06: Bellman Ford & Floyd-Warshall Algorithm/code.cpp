#include<iostream>
#include<vector>

using namespace std;

const int N=1000;
int inf=1e5;
vector<pair<int,int>>adjl[N];
int d[N];

int main()
{
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        d[i]=inf;
    }

    for(int i=0; i<m; i++)
    {
        int u, v,w;
        adjl[u].push_back({v,w});
    }

    int src=1;
    d[src]=0;

    for(int i=1; i<=n-1; i++)
    {
        for(int node=1; node<=n; node++)
        {
            for(auto adj_node:adjl[node])
            {
                int u=node;
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