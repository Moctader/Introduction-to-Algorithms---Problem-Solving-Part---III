#include<iostream>
#include<vector>
using namespace std;
const int N=2e5;
vector<int>adjList[N];
int visited[N];
int parent[N];
int st, ed;

bool cycle_detection(int src)
{
    visited[src]=1;
    for(auto adj: adjList[src])
        {
            if (adj==parent[src]) continue;
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
                st=src;
                ed=adj;
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
    for(int i=1; i<=edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }

    bool cycle =false;
    for(int i=0; i<nodes; i++)
    {
        bool ok=cycle_detection(i);
        if (ok)
        {
            cycle =true;
            break;
        }
        
    }

    if (cycle)
    {
        vector<int>cities;
        int temp=st;
        cities.push_back(st);

        while (temp!=ed)
        {
           cities.push_back(parent[temp]);
           temp=parent[temp];
        }
        cities.push_back(st);
        
        for(auto city: cities)
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

