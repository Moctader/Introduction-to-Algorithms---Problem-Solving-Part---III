
/*
5 5
1 2
1 3
1 4
2 3
5 4
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std; 
const int N=2000;
vector<int>adjlist[N];
int visited[N];
int level[N];
int parent[N];


void bfs(int node)
{
    queue<int>q;
    visited[node]=1;
    level[node]=1;
    parent[node]=-1;
    q.push(node);

    while (!q.empty())
    {
        int head=q.front();
        q.pop();
        for(auto adj: adjlist[head])
        {
            if (visited[adj]==0)
            {
                visited[adj]=1;
                level[adj]=level[head]+1;
                parent[adj]=head;
                q.push(adj);
            }
            
        }

    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int src=1;
    bfs(src);

    int dest_node=n;
    if (visited[dest_node]==0)
    {
       cout<<"impossible"<<"\n";
       return 0;
    }
    
    
    int selected_node=dest_node;
    vector<int>path;
    

    while (true)
    {
        path.push_back(selected_node);
        if (selected_node==src)
        {
           break;
        }
        
        selected_node=parent[selected_node];
    }

    reverse(path.begin(), path.end());
    
    for(auto val: path)
    {
        cout<<val<<" ";
    }
    cout<<"\n";
    

    return 0;
}