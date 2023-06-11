#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int N=1000;
map<ll, ll>ops;
int visited[N];

ll digit_count(int x)
{
    int res=0;
    while (x)
    {
        x=x/10;
        res++;
    }
    return res;
}


int solve(ll n, int x)
{
    queue<int>q;
    ops[x]=0;
    q.push(x);
    visited[x]=1;

    while (!q.empty())
    {
        ll curr=q.front();
        q.pop();
        if (digit_count(curr)==n)
        {
            cout<<ops[curr]<<endl;
            return 1;
        }
        int temp=curr;
        while (temp)
        {
            ll digit=temp%10;
            temp=temp/10;

            if (ops.find(digit*curr)==ops.end() && !visited[curr])
            {
                q.push(digit*curr);
                visited[curr]=1;
                ops[digit*curr]=ops[curr]+1;
            }
            
        }
        
        
    }
    return -1;
    
}

int main()
{
    int n, x;
    cin>>n>>x;
    cout<<solve(n, x);
    
    return 0;
}
