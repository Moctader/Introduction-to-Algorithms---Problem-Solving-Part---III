
/*

Test case
10 8
1 2
1 3
2 4
3 4
3 6
4 6
6 7
6 8

program is not working in the vs code but working in the online gdb.
*/


#include<iostream>
#include<vector>
#include<queue> 
using namespace std;
const int maxN=1e5;
bool visited[maxN];
vector<int>adj[maxN];

void bfs(int s)
{
    queue<int>q;
    cout<<s<<" ";
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto child : adj[node])
        {
            if(!visited[child])
            {
                visited[child]=true;
                cout<<child<<" ";
                q.push(child);
                
            }
        }
    }
    
}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=nodes; i++)
    {
        cout<<i<<"-> ";
        for(auto j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    bfs(1);
    return 0;
}