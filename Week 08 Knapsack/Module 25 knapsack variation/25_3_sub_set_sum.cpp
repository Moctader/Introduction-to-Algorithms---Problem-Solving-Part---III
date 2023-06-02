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
    
    
}

int main()
{
    int n, target;
    cin>>n>>target;

    for(int i=1; i<=n; i++)
    {
        cin>>nums[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=target; j++)
        {
            dp[i][j]=-1;
        }
    }

    cout<<subset_sum(n, target);

    return 0;
}


/*
6 9
3 34 4 12 5 2
target =9
*/