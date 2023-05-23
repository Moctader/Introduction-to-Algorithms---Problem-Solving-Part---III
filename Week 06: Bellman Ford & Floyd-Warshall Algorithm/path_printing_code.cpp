#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
const int N=10000;
ll inf=1e18;
ll d[N];
vector<pair<int, int>>adjl[N];
int parent[N];
int last_updated_note=-1;

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        d[i]=inf;
    }

    for(int i=1; i<=m; i++)
    {
        int u, v,w;
        adjl[u].push_back({v,w});   
    }

    bool negative_cycle=false;
    for(int i=1; i<=n; i++)
    {
        for(int node=1; node<=n; node++)
        {
            for(auto adj_node:adjl[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;

                if (d[u]+w<d[v])
                {
                    d[v]=d[u]+w;
                    u=parent[v];
                    if (i==n)
                    {
                        negative_cycle=true;
                        last_updated_note=v;

                    }
                    
                }
                
            }
        }
    }

    if (negative_cycle)
    {
        cout <<"yes";
        int selected_node=last_updated_note;
        for(int i=1; i<=n-1; i++)
        {
            selected_node=parent[selected_node];
        }
        int first_node=selected_node;
        vector<int>cycle;
        cycle.push_back(selected_node);
        while(true)
        {
            selected_node=parent[selected_node];
            if (selected_node==first_node)
            {
                break;
            }
            cycle.push_back(selected_node);
            
        }
        reverse(cycle.begin(), cycle.end());
        for(auto val:cycle)
        {
            cout<<val<<" ";
        }
    }
    


    return 0;
}