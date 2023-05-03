#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //vector<vector<int>>adj_list={{1,2},{0,2},{0,2,3},{2}};
        int n;
    cin>>n;
    vector<vector<int>>adj_list(n, vector<int>(n));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)

        {
            adj_list.push_back({j,i});
        }
    }

    int number_of_vertics=n;
    vector<vector<int>>adjMatrix(number_of_vertics, vector<int>(number_of_vertics, 0));

    for(int i=0; i<number_of_vertics; i++)
    {
        for(int j: adj_list[i])
        {
            adjMatrix[i][j]=1;
        }
    }

    for(int i=0; i<number_of_vertics; i++)
    {
        for(int j=0; j<number_of_vertics; j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        
        }
        cout<<"\n";
    }
    return 0;
}
