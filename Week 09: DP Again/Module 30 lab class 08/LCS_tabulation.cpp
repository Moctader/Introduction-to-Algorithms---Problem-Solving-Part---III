#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int N=3003;
int n,m;
int dp[N][N];
string s, t;

int main()
{

    cin>>s>>t;
    n=s.size();
    m=t.size();


    //base case
    for(int i=0; i<n; i++)
    {
        dp[i][m]=0;
    }

    for(int j=0; j<m; j++)
    {
        dp[n][j]=0;
    }

    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if (s[i]==t[j])
            {
                dp[i][j]=1+dp[i+1][j+1];
            }
            else
            {
                dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout<<dp[0][0];
    return 0;
}