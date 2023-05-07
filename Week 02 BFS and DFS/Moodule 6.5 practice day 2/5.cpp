#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MaxN=1000;

vector<int>adjMatrix[MaxN];
bool visited[MaxN];

bool bfs(int start, int target)
{
    queue<int>q;
    q.push(start);
    visited[start]=true;

    while (!q.empty())
    {
        int curr=q.front();
        q.pop();
        if (curr==target)
        {
            return true;
        }
        
        for(auto neighbour : adjMatrix[curr])
        {
            if (!visited[neighbour])
            {
                visited[neighbour]=true;
                q.push(neighbour);
            }
            
        }
    }
    return false;
    

}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adjMatrix[u].push_back(v);
        adjMatrix[v].push_back(u);

    }
    bool connected=bfs(2,6);
    if (connected)
    {
        cout<<"yes";
    }
    else
        cout<<"No";
    
    return 0;
}