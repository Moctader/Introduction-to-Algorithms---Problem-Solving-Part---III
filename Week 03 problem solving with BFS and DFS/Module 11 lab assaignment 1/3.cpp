#include<iostream>
#include<vector>
using namespace std;
const int N=2000;
vector<int>adjlist[N];
int visited[N];

bool DFS(int node)
{
    visited[node]=1;
    for(auto adj:adjlist[node])
    {
        if (visited[adj]==0)
        {
           bool exist_cycle= DFS(adj);
           if (exist_cycle)
           {
            return true;
           }
           
        }
        else if(visited[adj]==1)
        {
            return true;
        }
    }
    visited[node]=2;
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
        adjlist[u].push_back(v);

    }

    bool exist_cycle=false;
    for(int i=0; i<nodes; i++)
    {
        if (visited[i]==0)
        {
           bool find_cycle=DFS(i);
        
            if (find_cycle)
            {
                exist_cycle=true;
                break;
            }
        }
    }

    if (exist_cycle)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}