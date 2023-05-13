#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MN=2000;
int n,m;
bool visited[MN][MN];
vector<int>adjL[MN];
int maze[MN][MN];



void dfs(int i, int j)
{
    
     visited[i][j] = true;
    if (!maze[i][j]) { // if it's not a wall
        if (i > 0 && !visited[i-1][j]) dfs(i-1, j); // up
        if (i < n-1 && !visited[i+1][j]) dfs(i+1, j); // down
        if (j > 0 && !visited[i][j-1]) dfs(i, j-1); // left
        if (j < m-1 && !visited[i][j+1]) dfs(i, j+1); // right
    }
    
}

pair<int,int>find_visited()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (visited[i][j]==0 &&maze[i][j]==0)
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

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<maze[i][j]<<"\t";
        }
        cout<<"\n";
    }
    int num_room=0;
    while (1)
    {
        pair<int, int>find_cell_pos=find_visited();
        if (find_cell_pos==pair<int,int>{-1,-1})
        {
           break;
        }
        dfs(find_cell_pos.first, find_cell_pos.second);
        num_room++;
    }
    cout<<num_room;
    return 0;
}