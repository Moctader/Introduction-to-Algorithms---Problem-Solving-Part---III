#include<iostream>
#include<vector>
using namespace std;

const int N=60;
const int M=10001;
int MOD=1e9+7;
int dp[N][M];
int coins[N], limits[N];
int n, k;


int main()
{
    int t, tst=0;
    cin>>t;
    while (t--)
    {
        
        cin>>n>>k;

        for(int i=1; i<=n; i++)
        {
            cin>>coins[i];
        }

    

        for(int i=1; i<=n; i++)
        {
            for(int target=1; target<=k; target++)
            {
                dp[i][target]=0;
            }
        }

        dp[0][0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int target =0; target<=k; target++)
            {
                 dp[i][target]=dp[i-1][target];
             
                    if (target-coins[i]<0)
                    {
                       dp[i][target]=dp[i-1][target];
                    }
                    
                    int ret=dp[i][target-i*coins[i]];
                    dp[i][target]=(dp[i][target]+ret)%MOD;
                
            }
        }

        cout<<"case "<<++tst<<":"<<dp[n][k];
    }
    
    return 0;
}