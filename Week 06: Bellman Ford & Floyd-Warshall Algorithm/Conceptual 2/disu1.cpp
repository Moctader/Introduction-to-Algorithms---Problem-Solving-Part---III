#include<iostream>
#include<vector>    
using namespace std;
const int maxn=1000;
int _parent[maxn], _rank[maxn];

int _find(int node)
{
    if (node==_parent[node])
    {
        return node;
    }
    int x=_find(_parent[node]);
    _parent[node]=x;
    return _parent[node];
}

void _union(int a, int b)
{
    a=_find(a);
    b=_find(b);

    if (_rank[a]< _rank[b])
    {
        _parent[a]=b;
    }
    else if (_rank[b]<_rank[a])
    {
        _parent[b]=a;
    }
    else
    {
        if (_rank[b]==_rank[a])
        {
            _parent[b]=a;
            _rank[a]++;
        }
        
    }
    
    
}
int main()
{
    for(int i=0; i<maxn; i++)
    {
        _parent[i]=i;
    }

    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        _union(u,v);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<_parent[i]<<" ";
    }
    return 0;
}