#include<iostream>
#include<vector>

using namespace std;

const int N=1010;
vector<int>adj[N];
int visited[N];
int parent[N];

bool cycle_detection(int src)
{
    visited[src]=1;
    for(auto adj:adj[src])
    {
        if (adj==parent[src])
        {
            continue;
        }
        if (visited[adj]==0)
        {
            parent[adj]=src;
            bool ok=cycle_detection(adj);
            if (ok)
            {
                return true;
            }
            
        }
        else if (visited[adj]==1)
        {
            return true;
        }
        
        
    }
    visited[src]=2;
    return false;
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle=false;
    for(int i=0; i<nodes; i++)
    {
        bool ok=cycle_detection(i);
        if (ok)
        {
            cycle=true;
            break;
        }
        

    }

    if (cycle)
    {
        cout<<"Cycle Exist";
    }
    else
    {
        cout<<"No Cycle";
    }
    
    return 0;
}