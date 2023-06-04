/*

Problem Statement
There is a grid with 
H horizontal rows and 
W vertical columns. Let 
(i,j) denote the square at the 
i-th row from the top and the 
j-th column from the left.

For each 
i and 
j (
1≤i≤H, 
1≤j≤W), Square 
(i,j) is described by a character 
a 
i,j
​
 . If 
a 
i,j
​
  is ., Square 
(i,j) is an empty square; if 
a 
i,j
​
  is #, Square 
(i,j) is a wall square. It is guaranteed that Squares 
(1,1) and 
(H,W) are empty squares.

Taro will start from Square 
(1,1) and reach 
(H,W) by repeatedly moving right or down to an adjacent empty square.

Find the number of Taro's paths from Square 
(1,1) to 
(H,W). As the answer can be extremely large, find the count modulo 
10 
9
 +7.

Constraints
H and 
W are integers.
2≤H,W≤1000
a 
i,j
​
  is . or #.
Squares 
(1,1) and 
(H,W) are empty squares.

*/


#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<char>>grid(n, vector<char>(m, 'a'));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(n+5, vector<int>(m+5, 0));

    dp[0][0]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (i>0 && grid[i][j]!='#')
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
            if (j>0 && grid[i][j]!='#')
            {
                dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}
