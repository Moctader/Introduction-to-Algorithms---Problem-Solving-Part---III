#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
using namespace std;
const int N=1e5+5;
int dp[N];

int numsquares(int n)
{
    if (sqrt(n) == floor(sqrt(n)))
        return 1;

    if (dp[n]!=-1)
    {
        return dp[n];
    }

    int ans=INT_MAX;
    for(int i=1; i*i<=n; i++)
    {
        int square_value=numsquares(n-i*i);
        ans=min(ans, square_value+1);
    }
    dp[n]=ans;
    return ans;
    

}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        dp[i]=-1;
    }
    cout<<numsquares(n);

    return 0;
}
