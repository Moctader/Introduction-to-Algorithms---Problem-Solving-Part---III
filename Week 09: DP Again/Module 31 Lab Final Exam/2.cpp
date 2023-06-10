#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
const int N=1000;
ll inf=1e5+5;
ll dist[N];
int visited[N];
int parent[N];
int nodes, edges;
vector<pair<ll, int>>adj_list[N];

void shortest_path(int src)
{
    for(int i=1; i<=nodes; i++)
    {
        dist[i]=inf;
    }

    dist[src]=0;
    priority_queue<pair<ll, int>>pq;
    pq.push({0, src});

    while (!pq.empty())
    {
       pair<int, int>head=pq.top();
       pq.pop();
       int selected_node=head.second;

       for(auto adj_entry:adj_list[selected_node])
       {
            int adj_node=adj_entry.first;
            int cost=adj_entry.second;
            if (dist[selected_node]+cost<dist[adj_node])
            {
                dist[adj_node]=dist[selected_node]+cost;
                parent[adj_node]=selected_node;
                pq.push({-dist[adj_node], adj_node});
            }
            
       }
    }
    
}

int main()
{
    cin>>nodes>>edges;
    for(int i=1; i<=edges; i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});

    }
    int src;
    cin>>src;
    int dest_node;
    cin>>dest_node;
    shortest_path(src);
    if (dist[dest_node]>0)
    {
       cout<<dist[dest_node];
    }
    else
    {
        cout<<-1;
    }
    
    
    return 0;
}
