#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
int h[N];
int dp[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>h[i];
    }
  
    dp[0]=h[0];
    dp[1]=max(h[0],h[1]);
    for(int i=2; i<=n; i++)
    {
        int ans_1=dp[i-1];
        int ans_2=dp[i-2]+h[i];
        dp[i]=max(ans_1,ans_2); 
    }
    cout<<dp[n];
    return 0;
}
