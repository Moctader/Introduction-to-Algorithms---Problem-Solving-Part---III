#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int N=10000;
ll inf=1e9;
ll d[N];
int parent[N];
vector<pair<int, int>>adjl[N];

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
        cin>>u>>v>>w;
        adjl[u].push_back({v,w});
    }

    int last_updated_node=-1;
    bool negative_cycle=false;
    for(int i=1; i<=n; i++)
    {
        for(int node=1; node<=n; node++)
        {
            for(auto adj_node: adjl[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;
                if (d[u]+w<d[v])
                {
                    
                    d[v]=d[u]+w;
                    parent[v]=u;
                    if (i==n)
                    {
                        negative_cycle=true;
                        last_updated_node=v;
                    }
                    

                }
                
                
            }
        }
    }


    if(negative_cycle==true)
    {
        cout<<"YES"<<endl;

        int selected_node=last_updated_node;
        for(int i=1; i<=n-1; i++)
        {
            selected_node=parent[selected_node];
        }
        int first_node=selected_node;
        vector<int>cycle;
        cycle.push_back(selected_node);
        while (true)
        {
            selected_node=parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node==first_node)
            {
                break;
            }
            
            
        }
        reverse(cycle.begin(), cycle.end());
        for(auto val: cycle)
        {
            cout<<val<<" ";
        }
        
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
 