#include<iostream>
#include<vector>
using namespace std;

const int N=60;
const int k=1001; //k here just a varaible name nothing else
int dp[N][N];
int MOD=1e9+7;
int coins[N], Limits[N];

int fun(int n, int k)
{
    if (n==0)
    {
        if (k==0) return 1;
        return 0;
    }
   

    if (dp[n][k]!=-1)
    {
        return dp[n][k];
    }

    int ans=fun(n-1, k);

    for(int i=1; i<=Limits[n]; i++)
    {
        if (k-i*coins[n]<0)
        {
            break;
        }
        
        int ret=fun(n-1, k-i*coins[n]);
        ans=(ans+ret)%MOD;
    }
    dp[n][k]=ans;
    return ans;
    
    
}


int main()
{
    int t, tst=0;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        for(int i=1; i<=n; i++)
        {
            cin>>coins[i];
        }

        for(int i=1; i<=n; i++)
        {
            cin>>Limits[i];
        }

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                dp[i][j]=-1;
            }
        }

        cout<<"Case"<<++tst<<" : "<<fun(n,k)<<endl;
        
    }
    
    return 0;
}

/*
2
3 5
1 2 5 3 2 1

4 20
1 2 3 4 8 4 2 1
*/