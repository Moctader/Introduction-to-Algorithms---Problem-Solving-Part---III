#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

const int maxN=100;

int main()
{
   int e, n;
   cin>>n>>e;
   vector<pair<int, int>>adjList[maxN];
   for(int i=0; i<e; i++)
   {
    int u, v, w;
    cin>>u>>v>>w;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
   } 

   for(int i=0; i<n; i++)
   {
    cout<<i<<"--> ";
    for(auto j: adjList[i])
    {
        cout<<"{"<<j.first<<","<<j.second<<"}"<<",";
    }
    cout<<"\n";
   }
    return 0;
}