/*

wrong answer
code has some issues
*/


#include<iostream>  
#include<vector>
using namespace std;
const int maxN=2000;
vector<int>adjlist[maxN];
vector<bool>visited(maxN);
void dfs(int src)
{
    visited[src]=true;
    for(auto child: adjlist[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
        
    }
}
int main()
{
    int nodes, edges;
    cin>>edges>>nodes;
    for(int i=1; i<=edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

    }
    vector<int>ans;
    for(int i=1; i<=nodes; i++)
    {
        if (!visited[i])
        {
            ans.push_back(i),
            dfs(i);
        }
        
    }
    if (ans.size()<=1)
    {
        cout<<0<<"\n";
    }
    else
    {
        vector<pair<int,int>>roads;
        for(int i=1; i<=ans.size()-1; i++)
        {
            roads.push_back({ans[i], ans[i+1]});
        }
        cout<<roads.size()<<"\n";

        for(auto val: roads)
        {
            cout<<val.first<<" "<<val.second<<"\n";
        }

    }
    


    return 0;
}