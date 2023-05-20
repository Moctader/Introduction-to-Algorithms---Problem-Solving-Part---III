/*

Bangladesh has n cities, and m roads between them.You can go from one city to another if there exists a path between those two cities.
The goal is to  reach from city 1 to n.
Input -
The first input line has two integers n and m the number of cities and roads. The cities are numbered 1,2,…,n .After that, there are m lines describing the roads. Each line has two integers a and b. There is a road between those cities.A road always connects two different cities, and there is at most one road between any two cities.
Output - Print "YES" if your goal is possible, and "NO" otherwise.
Constraints-
2<=n<=10^5 , 1<=m<=2*10^5 , 1<=a,b<=n
**Write a C++ program for this problem**


*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int cities, roads;
const int N=10000;
vector<int>adjl[N]; 
int visited[N];
int parent[N];


void find_roads(int node)
{
    queue<int>q;
    visited[node]=1;
    q.push(node);

    while (!q.empty())
    {
        int head=q.front();
        q.pop();

        for(auto adj:adjl[head])
        {
            if (visited[adj]==0)
            {
                visited[adj]=1;
                q.push(adj);
            }
            
        }
    }
    

}

int main()
{
    cin>>cities>>roads;
    for(int i=0; i<roads; i++)
    {
        int u, v;
        cin>>u>>v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    int src=1;
    int destination=cities;
    find_roads(src);

    if (visited[destination]==0)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
    
  
    
    return 0;
}