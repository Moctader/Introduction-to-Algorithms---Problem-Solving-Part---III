#include<iostream>
#include<vector>
using namespace std;
const int N=1001;
int dp[N][N];

int max_value_sum(vector<int> & wt_p, vector<int> & val_p, int size, int weight)
{
    if (size==0 || weight==0)
    {
        return 0;
    }
    if (dp[size][weight]!=-1)
    {
       return dp[size][weight];
    }
    

    if (wt_p[size-1]<=weight)
    {
        return dp[size][weight]=max(val_p[size-1]+max_value_sum(wt_p, val_p, size-1, weight-wt_p[size-1]),max_value_sum(wt_p, val_p, size-1, weight));
    }
    else
    {
        return dp[size][weight]= max_value_sum(wt_p, val_p, size-1, weight);
    }
    
    
}

int main()
{
    int n, weightsof_bag;
    cin>>n>>weightsof_bag;
    vector<int>wt_p(n), val_p(n);
    for(int i=0; i<n; i++)
    {
        int weights_of_product, value_of_product;
        cin>>weights_of_product>>value_of_product;
        wt_p[i]=weights_of_product;
        val_p[i]=value_of_product;
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=weightsof_bag; j++)
        {
            dp[i][j]=-1;
        }
    }

    cout<<max_value_sum(wt_p, val_p, n, weightsof_bag);
    return 0;
}