/*
0 0 1 1 0 0
0 0 1 1 0 1
1 1 0 0 1 0
1 1 0 0 0 1
0 0 1 0 0 1
0 1 0 1 1 0

*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MaxN=1000;
vector<int>adjl[MaxN];
int graph[MaxN][MaxN];
int visited[MaxN];
int parent[MaxN];
int st, ed;

void bfs(int node, int dest)
{
    queue<int>q;
    visited[node]=1;
    q.push(node);
    parent[node]=-1;

    while (!q.empty())
    {
       int head=q.front();
       q.pop();

        if(head==dest)
        {
            vector<int>path;
            while (dest!=-1)
            {
                path.push_back(dest);
                dest=parent[dest];
            }
            reverse(path.begin(), path.end());
            cout<<path.size()<<endl;
            for(auto child :path)
            {
                cout<<child<<" ";
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
        for(int j=1; j<=edges; j++)
        {
            cin>>graph[i][j];
            if (graph[i][j]==1)
            {
                adjl[i].push_back(j);
            }
            
        }
    }

    for(int i=1; i<=edges; i++)
    {
        cout<<i<<" -> ";
        for(int j=1; j<=adjl[i].size(); j++)
        {
            cout<<adjl[i][j] <<" ";
        }
        cout<<"\n";
    }

    int src=1;
    bfs(src, nodes);
   
    return 0;
}