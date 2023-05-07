#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MaxN=1000;
int graph[MaxN][MaxN];
bool visites[MaxN];

void bfs(int start, int n)
{
    queue<int>q;
    q.push(start);
    visites[start]=true;


    while (!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i =0; i<n; i++)
        {
            if (!visites[i] && graph[curr][i]==1)
            {
                visites[i]=true;
                q.push(i);
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
        graph[u][v]=graph[v][u]=1;
    }
    bfs(0, nodes);
    return 0;
}