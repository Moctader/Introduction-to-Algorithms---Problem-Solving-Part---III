#include<iostream>
#include<vector>
using namespace std;

int dfs(int x, int y, int n, int m,vector<vector<int>> & Matrix,vector<vector<int>> & dp )
{

    if (dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    vector<vector<int>>dir={{-1,0}, {1, 0}, {0,1},{0,-1}};
    int ans=1;
    
    for(int i=0; i<4; i++)
    {
        int X=x+dir[i][0];
        int Y=y+dir[i][1];

        if (X<0 || X>=n || Y<0 || Y>=m)
            continue;

        if (Matrix[X][Y]<=Matrix[x][y])
            continue;
        
        
        ans=max(ans, 1+dfs(X,Y, n,m, Matrix,dp));
    
    }
    dp[x][y]=ans;
    return ans;
}
int longest_increasing_path(vector<vector<int>> & Matrix)
{
    int n=Matrix.size();
    int m=Matrix[0].size();

    vector<vector<int>>dp(n+5, vector<int>(m+5, -1));
    int ans=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) 
        {
            ans=max(ans, dfs(i, j, n, m, Matrix, dp));
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>Matrix(n, vector<int>(m, 'a'));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>Matrix[i][j];
        }
    }

    cout<<longest_increasing_path(Matrix);


    return 0; 
}
