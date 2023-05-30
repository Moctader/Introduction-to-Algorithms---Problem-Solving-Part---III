#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main()
{
   int n, x;
   cin>>n>>x;
   vector<int>coins(n);
   for(int i=1; i<=n; i++)
   {
    cin>>coins[i];
   }
    vector<int>number_of_coin(x+1, INT_MAX);
    number_of_coin[0]=0;

    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=coins.size(); j++)
        {
            if (i-coins[j]>=0)
            {
                number_of_coin[i]=min(number_of_coin[i], number_of_coin[i-coins[j]]+1);
            }
            
        }
    }

    cout<<number_of_coin[x];
    return 0;
}