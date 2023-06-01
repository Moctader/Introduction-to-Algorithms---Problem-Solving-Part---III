#include<iostream>
#include<vector>
using namespace std;
const int N=1010;
const int inf=1e9+5;
int n, k;
int h[N], dp[N];

int stone_2(int n)
{
    if (n==1)
    {
        return 0;
    }

    if (dp[n]!=-1)
    {
        return dp[n];
    }

    int ans=inf;
    for(int i=1; i<=k; i++)
    {
        if (n-i<=0)
        {
            break;
        }
        
        int candidate_ans=stone_2(n-i)+abs(h[n]-h[n-i]);
        ans=min(ans, candidate_ans);
    }
    dp[n]=ans;
    return ans;
    
    
}

int main()
{
    cin>>n>>k;

    for(int i=1; i<=n; i++)
    {
        cin>>h[i];
    }

    for(int i=1; i<=n; i++)
    {
        dp[i]=-1;
    }

    cout<<stone_2(n);
    return 0;
}