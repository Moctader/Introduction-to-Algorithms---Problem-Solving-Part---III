#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m;
const int N=2000;
int maze[N][N];
int visited[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool is_inside(pair<int, int>coor)
{
    int x=coor.first;
    int y=coor.second;
    if (x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;
    
}

bool is_safe(pair<int, int>coor)
{
    int x=coor.first;
    int y=coor.second;

    if (maze[x][y]==-1)
    {
       return false;
    }
    return true;
    
}
void bfs(pair<int, int>src)
{
    queue<pair<int, int>>q;
    visited[src.first][src.second]=1;
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

            pair<int, int>adj={new_x, new_y};

            if (is_inside(adj) && is_safe(adj) && visited[new_x][new_y]==0)
            {
               visited[new_x][new_y]=1;
               q.push(adj);
            }
            


        }

    }
    
}

pair<int, int>find_unvisited()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (visited[i][j]==0 && maze[i][j]==0)
            {
                return {i,j};
            }
            
        }
    }
    return {-1,-1};
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;
        for(int j=0; j<m; j++)
        {
            if (input[j]=='#')
            {
                maze[i][j]=-1;
            }
        }
    }


    int num_room=0;
    while (1)
    {
        pair<int, int>unvisited_pos=find_unvisited();
    
        if (unvisited_pos==pair<int, int>{-1,-1})
        {
            break;
        }
        bfs(unvisited_pos);
        num_room++;
        
    }
    cout<<num_room<<endl;


     
    return 0;
}