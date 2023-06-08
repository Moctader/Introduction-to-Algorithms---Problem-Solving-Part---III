#include<iostream>
#include<vector>
using namespace std;
const int N=101;
const int M =1e5+5;
int dp[N][M];
int coins[N];

int coin_change(int n, int target)
{
    if(n==0)
    {
        if(target==0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[n][target]!=-1)
    {
        return dp[n][target];
    }
    
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int ans1=coin_change(n-1, target);
        if (target<coins[n]*i)
        {
            dp[n][target]=ans1;
            return ans1;
        }
        int ans2=coin_change(n-1, target-i*coins[n]); 
        int ans=ans1+ans2;   
    }
    
    dp[n][target]=ans;
    return ans;
}

int main()
{
    int n, target;
    cin>>n>>target;
    for(int i=1; i<=n; i++)
    {
        cin>>coins[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=target; j++)
        {
            dp[i][j]=-1;
        }
    }

    cout<<coin_change(n, target);

    return 0;
}

//Not working properly