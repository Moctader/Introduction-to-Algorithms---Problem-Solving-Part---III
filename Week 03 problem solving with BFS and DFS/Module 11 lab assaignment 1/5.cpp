#include <iostream>
#include <vector>

using namespace std;
const int N=2000;
vector<int>adjlist[N];
int visited[N];

int dfs(int node)
{
    visited[node]=1;
    int count =0;
    for(auto adj:adjlist[node])
    {
        if (visited[adj]==0)
        {
            count++;
            dfs(adj);
            count++;
           
        }
        

    }
    return count;
}
int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    bool ok=true;
    for(int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            int value=dfs(i);
        }
        ok=false;
        cout << "Number of connected components: " << value << endl;
        
    }
    
    return 0;
}
