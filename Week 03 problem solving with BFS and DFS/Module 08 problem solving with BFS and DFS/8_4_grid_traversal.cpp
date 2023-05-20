

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
const int N=2000;
int visited[N][N];
int level[N][N];
int maze[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};


bool is_inside(pair<int, int>coor)
{
    int x=coor.first;
    int y=coor.second;
    if (x>0 && x<n && y>0 && y<m)
    {
        return true;
    }
    return false;
    
}

bool is_safe( pair<int, int>coor)
{
    int x=coor.first;
    int y=coor.second;
    if (maze[x][y]==-1)
    {
        return false;
    }

    return true;
    

}
void dfs(pair<int, int>src)
{
    queue<pair<int, int>>q;
    visited[src.first][src.second]=1;
    level[src.first][src.second]=0;
    q.push(src);

    while (!q.empty())
    {
        pair<int, int>head=q.front();
        q.pop();

        int x=head.first;
        int y=head.second;

        for(int i=0; i<4; i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];

            pair<int, int>adjNode={new_x, new_y};

            if (is_inside(adjNode) && is_safe(adjNode) && visited[new_x][new_y]==0)
            {
                visited[new_x][new_y]=1;
                level[new_x][new_y]=level[x][y]+1;
                q.push(adjNode);
            }
            
        }
    }
    

    
}
int main()
{
    cin>>n>>m;
    pair<int, int>src, dst;

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; i<m; j++)
    //     {
    //         level[i][j]=-1;
    //     }
    // }

    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j=0; j<m; j++)
        {
            if (s[j]=='#')
            {
                maze[i][j]=-1;
            }
            else if (s[j]=='A')
            {
                src={i, j};
            }
            else if (s[j]!='M')
            {
                dst={i, j};
            }
            
        }

    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<maze[i][j]<<"\t";
        }
        cout<<"\n";
    }

    dfs(src);
    if (!visited)
    {
        cout<<"No";
    }
        cout<<"yes";
    
    cout<<level[dst.first][dst.second];
    return 0;
}