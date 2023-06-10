#include<iostream>
#include<vector>
using namespace std;



int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    int dp[x+1];
  
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    
    dp[0]=1;
    for(int i=1; i<=x; i++)
    {
         dp[i]=0;
        for(auto val: v)
        {
     
            if (val<=i)
            {
                dp[i]=(dp[i]+dp[i-val]);
            }
        }
            
        
    }
    cout<<dp[x];

    return 0;
}
