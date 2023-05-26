#include<iostream>
#include<vector>

using namespace std;
const int N=1e3+3;
int inf=1e9;
int grid[N][N];

int main()
{
    int m,n;
    cin>>n>>m;
    // putting all the values of the grid is infinity

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            grid[i][j]=inf;
        }
    }

    //putting corner values equal to zero

    for(int i=1; i<=n; i++)
    {
        grid[i][i]=0;
    }

    //putting grid edge values weight

    for(int i=1; i<=m; i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        grid[u][v]=w;
    }

    //putting conditions for the Floyd-warshall

    for(int k=1; k<=n; k++)
    {
        for(int u=1; u<=n; u++)
        {
            for(int v=1; v<=n; v++)
            {
                grid[u][v]=min(grid[u][v], grid[u][k]+grid[k][v]); 
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<< grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}