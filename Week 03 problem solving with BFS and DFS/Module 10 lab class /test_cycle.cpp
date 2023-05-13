#include<iostream>
#include<vector>
using namespace std;
const int N=2e5;
vector<int>adjlist[N];
int visited[N];

bool detect_cycle(int country)
{
    visited[country]=1;
    for(auto neighbour:adjlist[country])
    {
        if (visited[neighbour]==0)
        {
            bool cycle_exist=detect_cycle(neighbour);
            if (cycle_exist)
            {
                return true;
            }
            
        }
        else if(visited[neighbour]==1)
        {
            return true;
        }
        
    }
    visited[country]=2;
    return false;
}

int main()
{
    int country, flights;
    cin>>country>>flights;
    for(int i=0; i<flights; i++)
    {
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
    }

    bool cycle_exist=false;
    for(int i=1; i<=country; i++)
    {
        if (visited[i]==0)
        {
            bool got_cycle=detect_cycle(i);
            if (got_cycle)
            {
                cycle_exist=true;
                break;
            }
            


        }
        
    }
    if (cycle_exist)
    {
        cout<<"yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    
    return 0;
}