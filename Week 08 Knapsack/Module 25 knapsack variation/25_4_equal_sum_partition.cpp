#include<iostream>
#include<vector>
using namespace std;
const int N=102;
const int M=1e5+5;
int dp[N][M];
int nums[N];


int subset_sum(int n, int target)
{
    if (n==0)
    {
        if (target==0) return 1;
        return 0;
    }

    if (dp[n][target]!=-1)
    {
        return dp[n][target];
    }

    int ans1= subset_sum(n-1, target);
    if (target<nums[n])
    {
        dp[n][target]=ans1;
        return ans1;
    }
    
    int ans2=subset_sum(n-1, target- nums[n]);
    int ans=ans1 || ans2;
    dp[n][target]=ans;
    return ans;
    
    
}int main()
{
    int n, target;
    int sum=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>nums[i];
        sum+=nums[i];
    }
    if (sum%2==0)
    {
         target=sum/2;
            }
    else
    {
        cout<<"can not answer";

    }

    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<subset_sum(n, sum/2);

    
    return 0;
}
