#include<iostream>
#include<vector>
using namespace std; 
const int N=1010;
int coin[N];

int mini_ways(int coin[], int n, int target)
{
    if (n==0 || target ==0)
    {
        return 0;
    }
    
    if (target>=coin[n])
    {
        return min(mini_ways(coin, n, target-coin[n]),mini_ways(coin, n-1, target));
    }
    else
    {
       return mini_ways(coin, n-1, target);
    }
    
}
int main()
{
    int n, w;
    cin>>n>>w;
    for(int i=1; i<=n; i++)
    {
        cin>>coin[i];
    }
    cout<<mini_ways(coin, n ,w);

    return 0;
}