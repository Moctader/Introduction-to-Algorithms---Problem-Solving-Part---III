#include<iostream>
#include<vector>
#include<list>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int nodes=4;
    //vector<int>adj_nodes[nodes];
    vector<pair<int, int> >adj_list[nodes];
    // adj_nodes[0]={1};
    // adj_nodes[1]={1,3,4};
    // adj_nodes[2]={1,5};
    // adj_nodes[3]={1,2};
    adj_list[0]={{1,2}};


    for(int i=0; i<nodes; i++)
    {
        cout<<"nodes "<<i<<" :";
        for(int j=0; j<adj_list[i].size(); j++)
        {
            cout<<"{"<<adj_list[i][j].first<<","<<adj_list[i][j].second<<"}";
        }
        cout<<endl;
    }
    return 0;
}