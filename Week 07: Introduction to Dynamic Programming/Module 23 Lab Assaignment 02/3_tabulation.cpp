#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
vector<int>dp(N, 0);
vector<int>count(N,0);


int points(vector<int>&values)
{
    
    if (values.size()==0)
    {
        return 0;
    }
    int n=values.size();

    for(int i=0; i<n; i++)
    {
        count[values[i]]++;
    }

    dp[1]=count[1];

    for(int i=2; i<=N; i++)
    {
    
        dp[i]=max(dp[i - 1], dp[i - 2]+count[i] * i);
    }
    return dp[N];
}

int main()
{
    int n; 
    cin>>n;

    vector<int>values(n);
    for(int i=0; i<n; i++)
    {
        cin>>values[i];
    }

    cout<<points(values);
    return 0;
}