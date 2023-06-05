#include<iostream>
#include<vector>
using namespace std;

int minimum_sum_path(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if (n==0)
    {
        if (m==0)
        {
            return 1;
        }
        
    }

    if (dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    int ans=0;
    if(n>0) ans=min(ans, grid[n-1][m]+grid[n][m]);
    if(m>0) ans=
    
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>grid(n, vector<int>(m, '1'));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    vector<vector<int>>dp(n, vector<int>(m, -1));
    minimum_sum_path(n, m, grid, dp);
    return 0;
}