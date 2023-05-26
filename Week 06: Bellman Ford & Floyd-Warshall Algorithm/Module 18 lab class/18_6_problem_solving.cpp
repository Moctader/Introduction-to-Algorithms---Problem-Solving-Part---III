#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;


ll inf=1e10;
const int N=1e3;
ll dist[N][N];

int main()
{
    int n, m,q;
    cin>>n>>m>>q;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dist[i][j]=inf;
        }
    }

    for(int i=1; i<=m; i++)
    {
        int  u, v;
        ll w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v], w);
        dist[v][u]=min(dist[v][u], w);
    }

    for(int i=1; i<=n; i++)
    {
        dist[i][i]=0;
    }

    for(int k=1; k<=n; k++)
    {
        for(int u=1; u<=n; u++)
        {
            for(int v=1; v<=n; v++)
            {
                dist[u][v]=min(dist[u][v],dist[u][k]+dist[k][v]);
            }
        }
    }

    cout<<"\n";
    for(int i=0; i<q; i++)
    {
        int u, v;
        cin>>u>>v;
        if (dist[u][v]==inf)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<dist[u][v]<<endl;
        }

    }
return 0;
}

/*
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

*/

/*
5 
5 
8
-1
3
*/
