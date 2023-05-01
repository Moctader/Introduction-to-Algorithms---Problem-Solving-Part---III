#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>adjacentList(vector<vector<int>>matrix, int n)
{
    vector<vector<int>>adj_list(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (matrix[i][j]==1)
            {
                adj_list[i].push_back(j);
            }
            
        }
    }

    return adj_list;
}
 int main()
 {
     int n; 
     
    cin>>n;
    vector<vector<int>>matrix(n, vector<int>(n));
    cout << "Enter adjacency matrix: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }
 

    vector<vector<int>>adj_list=adjacentList(matrix, n);
    cout << "Adjacency list:" << endl;

    for(int i=0; i<n; i++)
    {
        cout<<i<<" :";
        for(int j=0; j<adj_list[i].size(); j++)
        {
            cout<<adj_list[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
 }