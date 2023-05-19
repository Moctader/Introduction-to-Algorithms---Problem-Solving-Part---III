/*
A

*/


#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

int nodes, edges;
const int N =2000;
int visited[N];
int d[N];
int inf=1e8;
vector<pair<char, int>> adjl[N];

int main()
{
    cin>>nodes>>edges;
    for(int i=1; i<=edges; i++)
    {
        char u, v;
        int w;
        cin>>u>>v>>w;
        adjl[u].push_back({v,w});
        adjl[v].push_back({u,w});
        
    }

    for(int i=1; i<=edges; i++)
    {
        cout<<i<<":";
        for(auto adj:adjl[i])
        {
            cout<<"{"<<adj.first<<","<<adj.second<<"}"<<", ";
        }
        cout<<"\n";
    }
    
    return 0;
}