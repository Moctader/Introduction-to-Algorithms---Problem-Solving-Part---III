#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int N=2000;
int visited[N];
stack<int>stack_value;
vector<int>adjList[N];

void dfs(int node)
{
    visited[node]=1;
    for(auto adj:adjList[node])
    {
        if (visited[adj]==0)
        {
           dfs(adj);
        }
        
    }
    stack_value.push(node);
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);

    }

    for(int i=1; i<=n; i++)
    {
        if (visited[i]==0)
        {
            dfs(i);
        }
        
    }

    while (!stack_value.empty())
    {
       cout<<stack_value.top()<<" ";
       stack_value.pop();
    }
    cout<<endl;
    
    return 0;
}