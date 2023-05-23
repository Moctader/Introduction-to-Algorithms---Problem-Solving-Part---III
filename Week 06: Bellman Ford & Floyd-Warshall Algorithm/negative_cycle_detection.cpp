#include<iostream>
#include<vector>
using namespace std;

const int N=1000;
int inf=1e5;
int d[N];
vector<pair<int, int>>adjl[N];

int main()
{
    //All values markes as infinity
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        d[i]=inf;
    }

    // input of the edges;
    for(int i=1; i<=m; i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        adjl[u].push_back({v,w});
    }


    //Negative cycle detection
    bool negative_cycle=false;
    for(int i=1; i<=n; i++)
    {
        for(int node=1; node<=n; node++)
        {
            for(auto adj_node: adjl[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;

                if (d[u]+w<d[v])
                {
                   d[v]=d[u]+w;
                   if (i==n)
                   {
                        negative_cycle=true;
                   }
                   
                }
                
            }
        }
    }

    //Results printed accorfing to the negative cycle
    if (negative_cycle)
    {
        cout<<"Graph has negative cycle";
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            cout<<d[i]<<" ";
        }
    }
    
    return 0;
}