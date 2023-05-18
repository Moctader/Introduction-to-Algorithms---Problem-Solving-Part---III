
/*
 5 6
 1 2 2
 2 5 5
 2 3 4
 1 4 1
 4 3 3
 3 5 1

 
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll inf=(ll)1e18;
ll dist[N];
int visited[N];
int parent[N];
vector<pair<int,int>>adjl[N];
int nodes, edges;

void djkekstra(int src)
{
    for (int i=1; i<=nodes; i++)
    {
        dist[i]=inf;
    }
    dist[src]=0;
    priority_queue<pair<ll, int>>pq;
    pq.push({0, src});
    
    
    while (!pq.empty())
    {
        pair<ll, int>head=pq.top();
        pq.pop();
        int selected_node=head.second;
        if(visited[selected_node]==1)continue;
        
        visited[selected_node]=1;
        
        for(auto adj_entry:adjl[selected_node])
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
        int u, v, w;
        cin>>u>>v>>w;
        
        adjl[u].push_back({v,w});
        adjl[v].push_back({u,w});
    }
    int src=1;
    djkekstra(src);
    cout<<dist[nodes]<<"\n";

    int selected_node=nodes;
    vector<int>path;

    while (true)
    {
        path.push_back(selected_node);
        if (selected_node==src)
        {
            break;
        }
        selected_node=parent[selected_node];
        
    }
    
    reverse(path.begin(),path.end());
    for(auto val:path)
    {
        cout<<val<<" ";
    }
    
    return 0;
}


