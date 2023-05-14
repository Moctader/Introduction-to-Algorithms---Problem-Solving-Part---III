/*
6
7
0 1
0 4
1 2
1 5
0 3
5 4
2 4
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=2000;
vector<int>adjlist[N];
bool visited[N];
int level[N];

void BFS(int node)
{
    queue<int>q;
    visited[node]=true;
    level[node]=0;
    q.push(node);

    while (!q.empty())
    {
        int head=q.front();
        q.pop();
        for(auto adj:adjlist[head])
        {
            if (visited[adj]==false)
            {
                visited[adj]=true;
                level[adj]=level[head]+1;
                q.push(adj);
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
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

    }
    int src=0;
    BFS(src);

    for(int i=0; i<nodes; i++)
    {
        cout<<"node "<<i<<" ->level: "<<level[i]<<"\n";
    }
    return 0;
}