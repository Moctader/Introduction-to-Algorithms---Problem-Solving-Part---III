#include<iostream>
#include<vector>
using namespace std;

int robery(vector<int>& nums)
{
    
    int n=nums.size();
    vector<int>dp(n, -1);
    if (n==0)
    {
        return 0;
    }
    if (n<=1)
    {
       return nums[0];
    }
    
    if (n>1 && n<=2)
    {
        return max(nums[0], nums[1]);
    }

    if (dp[n]!=-1)
    {
        return dp[n];
    }
    
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int vallue=robery[i-1];
        
    }
    dp[n]=ans;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0; i<n; i++)
    {
        int in;
        cin>>in;
        nums.push_back(in);
    }
    for(int i=0; i<n; i++)
    {
        
        cout<<nums[i];
    }

    robery(nums);
    return 0;
}
