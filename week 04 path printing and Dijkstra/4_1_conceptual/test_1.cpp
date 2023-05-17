#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MaxN=1e5+5;
const ll inf=(ll)9e18;
vector<pair<int, int>>adjlist[MaxN];
vector<bool>visited(MaxN);
ll dist[MaxN];


void djkstra(int s, int n)
{
    for(int i=1; i<=n; i++)
    {
        dist[i]=inf;
    }

    dist[s]=0;
    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,s});

    while (!pq.empty())
    {
        int u=pq.top().second;
        int cost=pq.top().second;
        pq.pop();
        if (visited[u])
        {
           continue;
        }
        visited[u]=true;
        
        for(auto child: adjlist[u])
        {
            int v=child.first;
            int c=child.second;

            if (cost+c<dist[v])
            {
                dist[v]=cost+c;

            }
            pq.push({dist[v],v});
            
        }
    }
    
}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
    }
    djkstra(1, nodes);

    for(int i=0; i<nodes; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
