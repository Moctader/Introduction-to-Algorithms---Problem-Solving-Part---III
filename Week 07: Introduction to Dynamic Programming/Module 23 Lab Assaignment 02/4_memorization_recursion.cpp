#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
int dp[N];

int fib(int n)
{
    if (n==0)
    {
        return 0;
    }

    if (n>0 && n<=2)
    {
        return 1;
    }
    
    if (dp[n]!=0)
    {
        return dp[n];
    }
    
    int ans=fib(n-1)+fib(n-2)+fib(n-3);
    return ans;
    
}
int main()
{
    int n; cin>>n;
    cout<<fib(n);
    return 0;
}