
/*

3 8
3 30
4 50
5 60
*/

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int N=102;
const int M=1e5+5;

int wt[N], val[N];
ll dp[N][M];

ll knapsack(int n, int cap)
{
    if (n==0)
    {
        return 0;
    }

    if (dp[n][cap]!=-1)
    {
        return dp[n][cap];
    }
    if (cap<wt[n])
    {
        ll ans=knapsack(n-1, cap);
        dp[n][cap]=ans;
        return ans;
    }
    

    ll ans1= val[n]+knapsack(n-1, cap-wt[n]);
    ll ans2= knapsack(n-1, cap);
    ll ans=max(ans1, ans2);
    dp[n][cap]=ans;
    return ans;
    
}

int main()
{
    int n, cap;
    cin>>n>>cap;

    for(int i=1; i<=n; i++)
    {
        cin>>wt[i]>>val[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=cap; j++)
        {
            dp[i][j]=-1;
        }
    }

    cout<<knapsack(n, cap);

    return 0;
}
