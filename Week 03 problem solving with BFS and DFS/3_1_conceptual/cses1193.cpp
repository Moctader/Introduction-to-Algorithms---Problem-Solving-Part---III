#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

const int MaxN=1010;
char grid[MaxN][MaxN];
bool visited[MaxN][MaxN];
pair<int, int>parent[MaxN][MaxN];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dir[4]={'D','R','U','L'};

void bfs(int x, int y, int n, int m)
{
    queue<pair<int, int>>q;
    q.push({x, y});
    visited[x][y]=true;
    parent[x][y]={-1,-1};

    while (!q.empty())
    {
        pair<int, int>u=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int dy_, dx_;
            dx_=u.first+dx[i];
            dy_=u.second+dy[i];

            if (dx_>=1 && dx_<=n && dy_>=1 && dy_<=m && !visited[dx_][dy_] && grid[dx_][dy_]!='#')
            {
                visited[dx_][dy_]=true;
                q.push({dx_, dy_});
                parent[dx_][dy_]=u;
            }
            
        }

    }
    

}
int main()
{

    int n, m;
    cin >> n >> m;
    int start_x, start_y, end_x, end_y;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    bfs(start_x, start_y, n, m);
    
    if (visited[end_x][end_y])
    {
        cout<<"yes"<<"\n";
        // for(int i=1; i<=n; i++)
        // {
        //     for(int j=1; j<=m; j++)
        //     {
        //         cout<<"{"<<parent[i][j].first<<","<<parent[i][j].second<<"}"<<" ";
        //     }
        //     cout<<"\n";
        // }

        vector<pair<int, int>>path;
        path.push_back({end_x, end_y});
        int x=end_x,y=end_y;
        while (parent[x][y]!=make_pair(-1,-1))
        {
            pair<int, int>p=parent[x][y];
            x=p.first, y=p.second;
            path.push_back({x, y});
        }
        reverse(path.begin(), path.end());




        for(auto val:path)
        {
            cout<<val.first<<" "<<val.second<<"\n";
        }

        string ans;
        for(int i=0; i<path.size()-1; i++)
        {
            for(int j=0; j<4; j++)
            {
                int dx_, dy_;
                dx_=path[i].first+dx[j];
                dy_=path[i].second+dy[j];
                if (dx_==path[i+1].first && dy_==path[i+1].second)
                {
                    ans.push_back(dir[j]);
                    break;
                }
                

            }
        }
        cout<<ans.size()<<"\n";
        cout<<ans<<endl;
        
    }
    
    return 0;
}
