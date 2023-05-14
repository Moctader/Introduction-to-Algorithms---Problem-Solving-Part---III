#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=2000;
vector<int>adjlist[N];
int visited[N];
int color[N];

bool dfs(int node)
{
    visited[node]=1;
    for(auto adj: adjlist[node])
    {
        if (visited[adj]==0)
        {
            if (color[node]==1)
            {
                color[adj]=2;
            }
            else 
                color[adj]=1;

            bool bipartitie=dfs(adj);
            if (!bipartitie)
            {
                return false;
            }
            
            
        }

        else
        {
            if (color[node]==color[adj])
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

    bool is_bipartit=true;
    for(int i=0; i<nodes; i++)
    {
        if (visited[i]==0)
        {
            color[i]=1;
            bool ok=dfs(i);
            if (!ok)
            {
               is_bipartit=false;
               break;
            }
            
        }
        
    }
    if (is_bipartit)
    {
       cout<<"YES";
    }
    else
        cout<<"NO";
    
    return 0;
}