#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
int h[N];
int dp[N];
int n;
int ans;

int max_coin(int n)
{
    if (n<=1)
    {
        return 0;
    }
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    for(int i=1; i<=n; i++)
    {
        dp[i]=max(dp[i-1], dp[i-2]+h[i]);
    }
    return dp[n];
    
}

int main()
{
    
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>h[i];
    }
    for(int i=1; i<=n; i++)
    {
        dp[i]=-1;
    }
    cout<<max_coin(n);

    return 0;

}
