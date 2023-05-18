/*

0 0 1 1 0 0
0 0 1 1 0 1
1 1 0 0 1 0
1 1 0 0 0 1
0 0 1 0 0 1
0 1 0 1 1 0
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin>>n;
    int matrix[n][n];
    vector<int>adj_list[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
            if (matrix[i][j]==1)
             {
                 adj_list[i].push_back(j);
             }
            
        }
    }
    
    cout<<"\n";
    
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
