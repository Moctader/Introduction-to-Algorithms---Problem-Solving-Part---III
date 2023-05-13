/*
8 11
8 7
7 3
3 6
3 2
3 1
1 4
4 0
0 2
0 6
6 7
1 2
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MaxN=2000;
vector<int>adjlist[MaxN];
vector<bool>visited(MaxN);
vector<int>level(MaxN);

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    visited[node]=true;
    level[node]=0;
    
    while (!q.empty())
    {
        int head=q.front();
        q.pop();
        for(auto child:adjlist[head])
        {
            if (visited[child]==false)
            {
                visited[child]=true;
                q.push(child);
                level[child]=level[head]+1;
            }
            
        }
    }
    
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

    int src=3;
    bfs(src);
    for(int i=0; i<=nodes; i++)
    {
        cout<<"nodes"<<i<<" level"<<level[i]<<"\n";
    }
    return 0;
}