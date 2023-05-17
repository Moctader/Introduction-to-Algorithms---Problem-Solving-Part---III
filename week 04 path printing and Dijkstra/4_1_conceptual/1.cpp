#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int Maxn=1e5+5;
vector<bool>visited(Maxn);
vector<pair<ll,ll>>adjlist[Maxn];
ll dist[Maxn];
const ll inf=(ll)9e18;

void djkstra(int s, int n)
{
    for(int i=1; i<=n; i++)
    {
        dist[i]=inf;
    }
    dist[s]=0;

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,s});

    while (!pq.empty())
    {
        ll u=pq.top().second;
        ll cost=pq.top().first;
        pq.pop();
        if (visited[u]) continue;
        visited[u]=true;

        for(auto child: adjlist[u])
        {
            ll v=child.first;
            ll c=child.second;

            if (cost+c<dist[v])
            {
                dist[v]=cost+c;
                pq.push({dist[v],v});
            }
            
        }
        
        
    }
    

}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=1; i<=edges; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});

    }
    djkstra(1, nodes);   
    for(int i=1; i<=nodes; i++)
    {
        cout<<dist[i]<<" ";
    } 
    cout<<"\n";
    return 0;
}
