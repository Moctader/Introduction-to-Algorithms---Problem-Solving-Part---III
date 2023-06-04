/*
code is not working properly 
test case
4 4
1 3
3 4
1 4
4 2


1 2
ans should be 3
*/

#include<iostream>
#include<vector>
using namespace std;
const int N=1e2+5;
vector<int>parent_list[N];
int dp[N];
int root, target_value;

int max_dist(int node)
{
    if (node==root)
    {
        return 1;
    }
    
    if (dp[node]!=-1)
    {
        return dp[node];
    }

    int ans=0;
    for(auto parent: parent_list[node])
    {
        int parent_dist=max_dist(parent);
        ans=max(ans, parent_dist);
        
    }
    ans++;
    dp[node]=ans;
    return ans;
    
}

int main()
{
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        parent_list[v].push_back(u);
        
    }

    for(int i=1; i<=n; i++)
    {
        dp[i]=-1;
    }

    cin>>root>>target_value;

    cout<<max_dist(target_value);

    return 0;
}