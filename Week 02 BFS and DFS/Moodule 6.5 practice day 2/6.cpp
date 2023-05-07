
/*


Not Working Code


*/



#include<iostream>
#include<vector>
using namespace std;

const int MaxN=1000;
bool visited[MaxN];
vector<int>adjM[MaxN];

bool dfs(int start, int target)
{
    if (start==target)
    {
        return true;
    }
    
    visited[start]=true;
    for(auto neighbour : adjM[start])
    {
        if (!visited[start])
        {
            dfs(start, target);
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
        adjM[u].push_back(v);
        adjM[v].push_back(u);
    }
    bool connected=dfs(2, 6);
    if (connected)
    {
       cout<<"yes";
    }
    else
        cout<<"No";

    return 0;
}