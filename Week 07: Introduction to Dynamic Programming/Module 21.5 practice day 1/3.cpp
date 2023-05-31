/*
You are given an integer array cost where cost[i] is the cost of ith step on a 
staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/

#include<iostream>
#include<vector>
using namespace std;
const int N=1010;
vector<int>v(N);
int dp[N];

int min_cost(vector<int>&v)
{
    int n=v.size();
    dp[0]=0;
    dp[1]=0;
    for(int i=2; i<=n; i++)
    {
        dp[i]=min(dp[i-1]+v[i-1], dp[i-2]+v[i-2]);
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int in;
        cin>>in;
        v.push_back(in);
        
    }
    cout<<min_cost(v);
    return 0;
}