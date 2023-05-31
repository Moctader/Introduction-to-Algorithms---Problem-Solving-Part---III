/*

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can 
you climb to the top?

*/



#include<iostream>
#include<vector>

using namespace std;
const int N=1010;
int dp[N];

int fib(int n)
{
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n; 
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}