#include<iostream>
#include<vector>
using namespace std;
const int N=60;
const int M=1001;
int dp[N][M];

int coin_change(vector<int> & wt, vector<int> & val, int size, int weight)
{
    if (size==0 || weight==0)
    {
        return 0;
    }

    if (dp[size][weight]!=-1)
    {
        return dp[size][weight];
    }
    
    if (wt[size-1]<=weight)
    {
        return dp[size][weight]=max(val[size-1]+coin_change(wt, val, size-1,
        weight-wt[size-1]),coin_change(wt, val, size-1, weight));
    }
    else
    {
        return dp[size][weight]=coin_change(wt, val, size-1, weight);
    }
    
}

int main()
{
    int n, w;
    cin>>n>>w;
    vector<int>wt(n), val(n);
    for(int i=0; i<n; i++)
    {
        int value, weight;
        cin>>weight>>value;
        val[i]=value;
        wt[i]=weight;
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            dp[i][j]=-1;
        }
    }

    cout<<coin_change(wt, val, n, w);
    return 0;
}
/*
3 8
3 30
4 50
5 60

90*/