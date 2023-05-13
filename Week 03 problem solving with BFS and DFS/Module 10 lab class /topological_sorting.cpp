/*
 
 5 3
 1 2
 3 1
 4 5

 */



#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int N=2e5;
int visited[N];
vector<int>adjlist[N];
stack<int>stack_value;

void dfs(int node)
{
    visited[node]=1;
    for(auto adj:adjlist[node])
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
        adjlist[u].push_back(v);

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
