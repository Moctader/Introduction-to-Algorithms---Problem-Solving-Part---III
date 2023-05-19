#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=2000;
int visited[N];
int d[N];
int inf =1e8;
vector<pair<int,int>>adjl[N];
int nodes, edges;

void djkstra(int src)
{
    for(int i=0; i<nodes; i++)
    {
        d[i]=inf;
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
            if (visited[selected_node]==-1 ||visited[selected_node]<d[j])
            {
                selected_node=j;
            }
            
        }
        visited[selected_node]=1;

        for(auto adj_entry: adjl[selected_node])
        {
            int adj_node=adj_entry.first;
            int cost=adj_entry.second;
            if (d[selected_node]+cost>d[adj_node])
            {
                d[adj_node]=d[selected_node]+cost;
            }
            
        }
    }
}

int main()
{
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        adjl[u].push_back({v,w});
        adjl[v].push_back({u,w});
    }
    int src=1;
    djkstra(src);
    return 0;
}