#include<iostream>  
#include<vector>
using namespace std;

const int N=2e5+5;
vector<int>adjlist[N];
int visited[N];
int color[N];


bool dfs(int node)
{
    visited[node]=1;
    for(auto adjNode:adjlist[node])
    {
        if (visited[adjNode]==0)
        {
            if (color[node]==1)
            {
                color[adjNode]=2;
            }
            else
            {
                color[adjNode]=1;
            }
            
            bool is_bicolorable=dfs(adjNode);
            if (! is_bicolorable)
            {
               return false;
            }
            
        }
        else
        {
            if (color[node]==color[adjNode])
            {
                return false;
            }
            
        }
        
    }
    return true;
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

    }

    bool is_bicolorable=true;
    for(int i=1; i<=nodes; i++)
    {
        if (visited[i]==0)
        {
            color[i]=1;
            bool ok=dfs(i);
            if (! ok)
            {
              is_bicolorable=false;
              break;
            }
            
        }
    }
    if (! is_bicolorable)
    {
        cout<<"Impossible";
    }
    else{
        for(int i=1; i<=nodes; i++)
        {
            cout<<color[i]<<" ";
        }
    }

    return 0;
}