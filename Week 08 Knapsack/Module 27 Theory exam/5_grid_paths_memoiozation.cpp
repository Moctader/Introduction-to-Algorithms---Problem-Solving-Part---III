#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;

ll solve(int n, int m, vector<vector<char>>&grid, vector<vector<ll>>&dp)
{
    if (n==0 & m==0)
    {
        return 1;
    }
    if (dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    int ans=0;
    if (n>0 && grid[n][m]!='*')
    {
        ans=ans+solve(n-1,m,grid,dp)%MOD;
    }
    
    if (m>0 && grid[n][m]!='*')
    {
        ans=ans+solve(n, m-1,grid,dp)%MOD;
    }
    dp[n][m]=ans%MOD;
    return ans;

}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>>grid(n, vector<char>(n, 'a'));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }

  

    vector<vector<ll>>dp(n+5, vector<ll>(n+5, -1));
    int l=grid.size();
    int k=grid[0].size();
   cout<<solve(l-1, k-1, grid, dp);
    
    return 0;
}