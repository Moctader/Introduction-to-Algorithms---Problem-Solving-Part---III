#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int nodes=4;
    vector<vector<int>>edge_list={
        {0,1,2},
        {3,4,6},
        {1,2,3}
        };

    for(int i=0; i<edge_list.size(); i++)
    {
        cout<<edge_list[i][0]<<"--"<<edge_list[i][1]<<" \n";
    }

    return 0;
}