#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int>&v, int n, int generate_sum, int target)
{
    if (n==0)
    {
        if (generate_sum==target)
        {
            return true;
        }
        return false;
        
    }

    return targetSum(v, n-1, generate_sum+v[n-1], target) or targetSum(v, n-1, generate_sum-v[n-1], target);
    
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
    if (targetSum(v, n, 0, target)==true)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}