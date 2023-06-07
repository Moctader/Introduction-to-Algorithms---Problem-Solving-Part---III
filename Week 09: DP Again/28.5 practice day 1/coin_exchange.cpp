#include<iostream>
#include<vector>
using namespace std;
const int N=101;
vector<int>coins(N), limits(N);
int dp[N][N];


int fewest_coin(vector<int> & coins, int amount)
{
    int n=coins.size();
    if (n==0 && amount==0)
    {
        return 0;
    }

    if (dp[n][amount]!=-1)
    {
        return dp[n][amount];
    }
    int ans=0;
    if (coins[n]<amount)
    {
        return ans=max(1+fewest_coin(coins[n-1], amount-coins[n]),fewest_coin(coins[n-1], amount));
    }
    else
    {
        ans=fewest_coin(coins[n-1], amount);
    }
    dp[n][amount]=ans;
    return ans;

    
}
int main()
{
    int n, amount;
    cin>>n>>amount;
    
    for(int i=0; i<=n; i++)
    {
        cin>>coins[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=amount; j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<fewest_coin(coins, amount);

    return 0;
}