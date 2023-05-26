#include<iostream>
#include<vector>
using namespace std;

int inf =1e5;
const int N=1000;
int d[N];
vector<pair<int, int>>adjl[N];



int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        d[i]=inf;
    }

    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adjl[u].push_back({v,w});

    }

    bool negative_cycle=false;
    for(int i=1; i<=n; i++)
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
                    if (i==n)
                    {
                        negative_cycle=true;
                    }
                    
                }
                
            }
        }
    }

    if (negative_cycle)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    


    return 0;
}