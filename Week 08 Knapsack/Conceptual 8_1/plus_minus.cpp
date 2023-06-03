#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int>&v, int n, int generate_sum, int target_sum)
{
    if (n==0)
    {
        if (generate_sum==target_sum)
        {
            return true;
        }
        return false;
    }

    return targetSum(v, n-1, generate_sum+v[n-1], target_sum) or targetSum(v, n-1, generate_sum-v[n-1], target_sum);
    
}

int main()
{
    int n, target; 
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    if (targetSum(v,n,0,target)==true)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}