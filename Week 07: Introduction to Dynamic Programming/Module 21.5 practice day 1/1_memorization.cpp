#include<iostream>
#include<vector>
using namespace std;
const int maxN=1010;
int  dp[maxN];

int fib(int n)
{
    if (n<=3)
    {
        return 1;
    }
    if (dp[n]!=0)
    {
        return dp[n];
    }
  
    dp[n]={fib(n-1)+fib(n-2)+fib(n-3)};
  
    return dp[n];
    
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}