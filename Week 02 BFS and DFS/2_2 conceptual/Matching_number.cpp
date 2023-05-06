#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if (n%2==0)
        {
            cout<<"No"<<"\n";
        }
        else
        {
            cout<<"Yes"<<"\n";
            vector<pair<int, int>>ans(n);
            int nxt=2*n;
            for(int i=0; i<n; i++)
            {
                ans[i].first=nxt;
                nxt--;
            }
            nxt=1;
            for(int i=0; i<=n/2; i++)
            {
                ans[i].second=nxt;
                nxt+2;
            }
            nxt=2;
            for(int i=n/2+1; i<n; i++)
            {
                ans[i].second=nxt;
                nxt+2;
            }
            for(auto val: ans)
            {
                cout<<val.first<<" "<<val.second<<"\n";
            }
        }
    }
    return 0;
}