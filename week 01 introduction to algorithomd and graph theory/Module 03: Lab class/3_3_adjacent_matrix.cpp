#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes;
    cin>>nodes;
    int Matrix[nodes][nodes]={};

    // for(int i=0; i<nodes; i++)
    // {
    //     for(int j=0; j<nodes; j++)
    //     {
    //         Matrix[i][j]=0;
    //     }
    //     cout<<endl;
    // }
    Matrix[0][1]=1;
    Matrix[1][0]=1;

    Matrix[1][2]=1;
    Matrix[2][1]=1;

    Matrix[2][3]=1;
    Matrix[3][2]=1;

    Matrix[1][3]=1;
    Matrix[3][1]=1;

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}