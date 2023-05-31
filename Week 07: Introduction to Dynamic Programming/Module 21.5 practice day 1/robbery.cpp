/*
You are a professional robber planning to rob houses along a street. Each house 
has a certain amount of money stashed, the only constraint stopping you from 
robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into 
on the same night.

Given an integer array nums representing the amount of money of each house, return
the maximum amount of money you can rob tonight without alerting the police.

*/

#include<iostream>
#include<vector>
using namespace std;
const int N=1010;
vector<int>V(N);
int dp[N];

int rob(vector<int>&v)
{
    int n=v.size();
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return v[0];
    }
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);

    for(int i=2; i<n; i++)
    {
        dp[i]=max(dp[i-1], dp[i-2]+v[i]);
    }
    
    return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {   
        int in;
        cin>>in;
        V.push_back(in);
    }
    int max_num_rob=rob(V);
    cout<<max_num_rob;

    return 0;
}