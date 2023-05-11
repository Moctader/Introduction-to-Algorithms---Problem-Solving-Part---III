/*

10 10
3 4
8 10
3 7
1 8
2 8
9 10
2 4
6 9
1 4
3 5
*/


#include<iostream>
#include<vector>
using namespace std;
const int MaxN=2020;
vector<int>adjlist[MaxN];
vector<bool>visited(MaxN);
vector<int>color(MaxN);

bool dfs(int node)
{
    visited[node]=true;
    for(auto adjNode:adjlist[node])
    {
        if (!visited[adjNode])
        {
            if (color[node]==1)
            {
                color[adjNode]=2;
            }
            else
            {
                color[adjNode]=1;
            }
            bool bicolorable=dfs(adjNode);
            if (!bicolorable)
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
    for(int i=1; i<=edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for(int i=1; i<=nodes; i++)
    {
        cout<<i<<"->";
        for(auto child :adjlist[i])
        {
            cout<<child<<" ";
        }
        cout<<"\n";
    }

    bool ok=true;
    for(int i=1; i<=nodes; i++)
    {
        if (!visited[i])
        {
            color[i]=1;
            bool yes=dfs(i);
            if (!yes)
            {
                ok=false;
                break;
            }
        }
        
        
       
    }

    if(ok)
        cout<<"yes";

    else
        cout<<"No";
    return 0;
}