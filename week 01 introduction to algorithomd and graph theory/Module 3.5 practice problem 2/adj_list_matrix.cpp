#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //vector<vector<int>>adj_list={{1,2},{0,2},{0,2,3},{2}};
    vector<vector<int>>adj_list;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)

        {
            cin>>adj_list[i][j];
        }
    }

    int number_of_vertics=adj_list.size();
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