#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>>adjl;
vector<int>visited;
vector<int>parent;

int find_parent(int x)
{
    if (parent[x]==-1)
    {
        return x;
    }
    return find_parent(parent[x]);
    
}

void union_operation(int a, int b)
{
    int parentA=find_parent(a);
    int parentB=find_parent(b);
    parent[parentA]=parentB;
}

int main()
{
    int n, m;
    cin>>n>>m;
    parent.resize(n, -1);
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        adjl.push_back({a,b});
    }

    bool cycle=false;
    for(int i=1; i<=n; i++)
    {
        int a=adjl[i].first;
        int b=adjl[i].second;

        int parentA=find_parent(a);
        int parentB=find_parent(b);
        if (parentA==parentB)
        {
            cycle=true;
            break;
        }
        else
        {
            union_operation(a,b);
        }
        
        
    }
    if (cycle)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"No";
    }

    return 0;
}

