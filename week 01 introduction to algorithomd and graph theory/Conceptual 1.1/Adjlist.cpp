#include<iostream>
#include<vector>
using namespace std;

const int maxN=100;
int main()
{
    int e, n;
    cin>>e>>n;
    vector<int>adjList[maxN+123];

    for(int i=0; i<e; i++)
    {
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<"--> ";
        for(auto j:adjList[i])
            {
                cout<<j<<" ";
            }
        cout<<"\n";
    }

    return 0;

}