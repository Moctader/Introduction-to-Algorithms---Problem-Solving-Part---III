#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int N=102;
const int M=1e5+5;
int wt[N], val[N];
ll dp[N][M];

int main()
{
    int n, w;
    cin>>n>>w;
    for(int i=1; i<=n; i++)
    {
        cin>>wt[i]>>val[i];
    }
  
    //handle base case
    for(int i=1; i<=w; i++)
    {
        dp[0][i]=0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int cap=1; cap<=w; cap++)
        {
            if (cap<wt[i])
            {
                dp[i][cap]=dp[i-1][cap];
            }
            else
            {
                 dp[i][cap]=max(val[i]+dp[i-1][cap-wt[i]], dp[i-1][cap]);
            }
            
            
        }
    }
    cout<<dp[n][w]<<endl;


    return 0;
}
