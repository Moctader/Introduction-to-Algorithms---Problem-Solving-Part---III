/*
Test Case:

6 6
0 1
2 3
1 5
1 2
2 4
5 4

*/



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MaxN=1e5;
vector<int>adj[MaxN];
bool visited[MaxN];
int level[MaxN];

void bfs(int src)
{
    queue<int>q;
    visited[src]=true;
    level[src]=0;
    q.push(src);

    while (!q.empty())
    {
        int head=q.front();
        q.pop();

        for(auto adjNode:adj[head])
        {
            if (visited[adjNode]==false)
            {
                visited[adjNode]=true;
                level[adjNode]=level[head]+1;
                q.push(adjNode);
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

    int src=0;
    bfs(src);

    for(int i=0; i<nodes; i++)
    {
        cout<<"nodes"<<i<<" Level :"<<level[i]<<"\n";
    }

    return 0;
}