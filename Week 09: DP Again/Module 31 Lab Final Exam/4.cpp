#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+5;
vector<pair<ll, ll>>v;

int main()
{
    int n, x;
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        v.push_back({temp, i+1});
    }

        int l=0, r=n-1;
        ll value=0;
        bool ans=false;
        while (r>l)
        {
            value=v[l].first+v[r].first;
            if (value==x)
            {
                ans=true;
                break;
                
            }
            if (value<x)
            {
                l++;
            }
            else
            {
                r--;
            }
   
        }
        if (ans)
        {
            cout<<v[l].second<<" "<<v[r].second;
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
    
    return 0;
}