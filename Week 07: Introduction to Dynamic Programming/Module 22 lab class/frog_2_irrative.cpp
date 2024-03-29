#include<iostream>
#include<vector>
using namespace std;

const int N=1010;
const int inf=1e9+5;

int h[N], dp[N];

int main()
{
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>h[i];
    }

    dp[1]=0;
    for(int i=2; i<=n; i++)
    {
        dp[i]=inf;
        for(int j=1; j<=k; j++)
        {
            int from_stone=i-j;
            if (from_stone<=0)
            {
                break;
            }
            int candidate_ans=dp[from_stone]+abs(h[i]-h[from_stone]);
            dp[i]=min(dp[i], candidate_ans);
            
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}