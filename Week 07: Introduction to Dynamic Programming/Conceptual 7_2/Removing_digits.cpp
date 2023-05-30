/*
you are given an integer n, on each step , you may subtract on e of the difits from the
number. How many steps require to make the number equal to zero.
*/

#include<iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;
const int maxN=1e6+18;
vector<int>dp(maxN, INT_MAX);

int solve(int i)
{
    if (i==0)
    {
       return 0;
    }
    
    if (dp[i]!=INT_MAX)
    {
        return dp[i];
    }
    
    vector<int>d;
    for(auto j:to_string(i))
    {
        d.push_back(j-'0');
    }
    for(auto val:d)
    {
        dp[i]=min(dp[i], solve(i-val)+1);
    }
    return dp[i];
}

int main()
{
    int n; 
    cin>>n;
    cout<<solve(n);
    return 0;
}