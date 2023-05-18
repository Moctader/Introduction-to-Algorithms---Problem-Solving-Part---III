#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+5;
vector<pair<int, int>>adjlist[N];
ll dist[N];
ll inf=(ll)1e18;
int nodes, edges;
int visited[N];
int parent[N];

void djkstra(int src)
{
    for(int i=1; i<=nodes; i++)
    {
        dist[i]=inf;
    }
    dist[src]=0;
    priority_queue<pair<ll, int>>pq;
    pq.push({0,src});

    while (!pq.empty())
    {
        pair<ll, int>head=pq.top();
        pq.pop();
        int slected_node=head.second;
        if (visited[slected_node]==1)
        {
            continue;
        }

        visited[slected_node]=1;

        for(auto adj_entry:adjlist[slected_node])
        {
            ll adj_node=adj_entry.first;
            int edge_cost=adj_entry.second;

            if (dist[slected_node]+edge_cost<dist[adj_node])
            {
                dist[adj_node]=dist[slected_node]+edge_cost;
                parent[adj_node]=slected_node;
                pq.push({-dist[adj_node], adj_node});
                
            }
            
        }
    }
    
}
int main()
{
    cin>>nodes>>edges;
    for(int i=1; i<=nodes; i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    int src=1;
    djkstra(src);
    cout<<dist[nodes]<<"\n";
    return 0;
}
