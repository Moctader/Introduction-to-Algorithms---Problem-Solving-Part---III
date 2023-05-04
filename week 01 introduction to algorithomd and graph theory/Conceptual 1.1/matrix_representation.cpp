#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, edges;
    cin>>n>>edges;
    int adjMatrix[n+1][n+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            adjMatrix[i][j]=0;
        }
    }

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }

        cout<<"\n";
    }
    return 0;
}