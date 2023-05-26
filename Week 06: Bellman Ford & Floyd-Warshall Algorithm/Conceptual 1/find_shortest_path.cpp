#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>parent;
vector<bool>visited;
vector<int>adjl[1000];


vector<int>find_path(int dest)
{
    vector<int>path;
    int x=dest;
    while (x!=-1)
    {
        path.push_back(dest);
        dest=parent[dest];
    }
    reverse(path.begin(), path.end());
    return path;
    
}

vector<int>bfs(int src, int dest)
{
    queue<int>q;
    visited[src]=true;
    q.push(src);
    vector<int>path={-1};

    if (!q.empty())
    {
        int p=q.front();
        q.pop();
        
        if (p==dest)
        {
            path=find_path(dest);
            return path;
        }
        

        for(auto adj_node:adjl[p])
        {
            if (visited[adj_node]==false)
            {
                visited[adj_node]=true;
                q.push(adj_node);
                parent[adj_node]=p;
            }
            
        }
    }
    return path;

}
int main()
{
    int n, m;
    cin>>n>>m;
    parent.resize(n, -1);
    visited.resize(n, false);


    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }

    int src, dest;
    cin>>src>>dest;
    vector<int>path= bfs(src, dest);

    for(auto val: path)
    {
        cout <<val<<" ";
    }

    return 0;
}
