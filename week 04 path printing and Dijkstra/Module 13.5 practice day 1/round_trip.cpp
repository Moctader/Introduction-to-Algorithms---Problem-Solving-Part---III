/*
5 6
1 3
1 2
5 3
1 5
2 4
4 5

//problem completely finnished
*/

#include<iostream>
#include<vector>
using namespace std;

const int maxN=2e5;
vector<int>adjl[maxN];
int visited[maxN];
int parent[maxN];
int st, ed;

bool cycle_detection(int src)
{
    visited[src]=1;
    for(auto adj_node:adjl[src])
    {
       if( parent[src]==adj_node)
       {continue;
       }
        if (visited[adj_node]==0)
        {
            parent[adj_node]=src;

            bool ok=cycle_detection(adj_node);
            if (ok)
            {
                return true;
            }
            
        }
        if (visited[adj_node]==1)
        {
            st=src;
            ed=adj_node;
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
    for(int i=0; i<nodes; i++)
    {
        int u, v;
        cin>>u>>v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    bool cycle=false;
    for(int i=0; i<nodes; i++)
    {
        if (visited[i]==0)
        {
            bool ok=cycle_detection(i);
            if(ok)
            {
                cycle=true;
                break;
            }
        }
        
    }

    if (cycle)
    {
        vector<int>cities;
        cities.push_back(st);
        int temp=st;
        while (temp!=ed)
        {
            cities.push_back(parent[temp]);
            temp=parent[temp];
        }
        cities.push_back(st);
        
        cout<<cities.size()<<"\n";
        for(auto city:cities)
        {
            cout<<city<<" ";
        }

    }
    else
    {
        cout<<"impossible";
    }
    
    return 0;
}
