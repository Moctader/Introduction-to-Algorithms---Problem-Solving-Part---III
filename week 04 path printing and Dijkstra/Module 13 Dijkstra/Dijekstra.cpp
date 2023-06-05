#include<iostream>
#include<vector>
using namespace std;
int nodes, edges;
const int N=1e1+5;
int visited[N];
int d[N];
int infinty=1e2;
vector<pair<int, int>>adjlist[N];

void djkstra(int src)
{
    for(int i=0; i<nodes; i++)
    {
        d[i]=infinty;
    }
    d[src]=0;

    for(int i=0; i<nodes; i++)
    {
        int selected_node=-1;
        for(int j=1; j<=nodes; j++)
        {
            if (visited[selected_node]==1)
            {
                continue;
            }
            if (d[selected_node]==-1 || d[selected_node]>d[j])
            {
                selected_node=j;
            }
            
        }
        visited[selected_node]=1;

        for(auto adj_entry: adjlist[selected_node])
        {
            int adj_node=adj_entry.first;
            int edge_cost=adj_entry.second;

            if (d[selected_node]+edge_cost>d[adj_node])
            {
                d[adj_node]=d[selected_node]+edge_cost;
            }
            
        }
    }
}

int main()
{
    cin>>nodes>>edges;
    for(int i=0; i<nodes; i++)
    {
        int u, v,w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }

    int src;
    djkstra(src);

    for(int i=0; i<nodes; i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<"\n";
    return 0;
}