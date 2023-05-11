#include<iostream>
#include<vector>
using namespace std;

const int MaxN=2000;
vector<int>adjlist[MaxN];
vector<bool>visited(MaxN);
vector<int>color(MaxN);

bool dfs(int node)
{
    visited[node]=true;
    for(auto child: adjlist[node])
    {
        if (!visited[child])
        {
            if (color[node]==1)
            {
            color[child]=2;
            }
            else
                color[child]=1;
            
            bool biparable=dfs(child);
            if (!biparable)
            {
                return false;
            }
            
        }
        else
            {
                if (color[node]==color[child])
                {
                    return false;
                }
                
            }
        

        
    }
    return true;
}

int main()
{
    int edges, nodes;
    cin>>edges>>nodes;
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
        {
            for(auto child:adjlist[i])
            {
                cout<<child<<" ";
            }
            cout<<"\n";
        }
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
    if (ok)
    {
        cout<<"yes";
    }
    else
        cout<<"No";
    
    return 0;
}