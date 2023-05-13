/*
 4 5
 1 3
 2 1
 2 4
 3 2
 3 4
 
 
 
 4 4
 1 3
 2 1
 2 4
 3 4

 
 */
#include<iostream>
#include<vector>
using namespace std;

const int mx=2e5;
int visited[mx];
vector<int>adjlist[mx];

bool dfs(int node)
{
    visited[node]=1;
    for(auto adj:adjlist[node])
    {
        //visited[node]=0 unvisited | apply dfs
        //visited[node]=1 paused |return true
        //visited[node]=2 done | continue

        if (visited[adj]==0)
        {
            bool got_cycle=dfs(adj);
            if (got_cycle)
            {
               return true;
            }
        }
            
        else if (visited[adj]==1)
            {
                return true;
            }
            
            
    }
    visited[node]=2;
    return false;

}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
    }
    bool got_cycle=false;
    for(int i=1; i<=n; i++)
    {
        if (visited[i]==0)
        {
            bool cycle= dfs(i);
            if (cycle)
            {
               got_cycle=true;
               break;
            }
            
        }
        
    }

    if (got_cycle)
    {
        cout<<"cycle exist"<<"\n";
    }
    else
        cout<<"No cycle"<<"\n";
    

  
    
    return 0;
}
