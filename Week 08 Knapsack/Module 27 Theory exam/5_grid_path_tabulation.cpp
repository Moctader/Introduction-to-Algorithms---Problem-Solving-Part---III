#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
//int dp[N][N];
int MOD=1e9+7;

int main()
{
    int n; 
    cin>>n;
    vector<vector<char>>grid(n, vector<char>(n, 'q'));
    for(int i=0;i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }
    int n1=grid.size();
    int m1=grid[0].size();
   vector<vector<int>>dp(n1, vector<int>(m1, 0));

    dp[0][0]=1;

    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<m1; j++)
        {
            if (i>0 && grid[i][j]!='*')
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
            if (j>0 && grid[i][j]!='*')
            {
                dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
            }
            
            
        }
    }

    cout<<dp[n1-1][m1-1];
    return 0;
}