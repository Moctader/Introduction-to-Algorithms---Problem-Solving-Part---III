#include<iostream>
#include<vector>
using namespace std;

bool reach_value(int cur, int target)
{
    if (cur==target)
    {
        return true;
    }
    if (cur>target)
    {
        return false;
    }

    return reach_value(cur*10, target) or reach_value(cur*20, target);
    
    
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n; 
        cin>>n;
        if (reach_value(1,n)==true)
        {
            cout<<"yes";
        }
        else
        {
            cout<<"no";
        }
        
    }
    
    return 0;
}