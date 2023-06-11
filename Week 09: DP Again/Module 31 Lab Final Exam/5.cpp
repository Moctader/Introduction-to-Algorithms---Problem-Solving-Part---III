#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

const int N=1001;
int Max_value=0;
bool dp[N+1][N+1];

int main()
{
    int n; 
    cin>>n;
    vector<int>coins_value(n);
    for(int i=0; i<n; i++)
    {
        cin>>coins_value[i];
        Max_value+=coins_value[i];

    }

    
    dp[0][0]=true;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=Max_value; j++)
        {
            dp[i][j]=dp[i-1][j];

            int prev_sum=j-coins_value[i-1];

            if (prev_sum>=0 && dp[i-1][prev_sum])
            {
                dp[i][j]=true;
            }
            
        }
    }


	vector<int> possible;
	for (int sum = 1; sum <= Max_value; sum++) 
    {
		if (dp[n][sum]) 
        { 
            possible.push_back(sum);  
        }
	}


	cout << (int)(possible.size()) << endl;

	for (int sum : possible) 
    { 
        cout << sum << " "; 
    }
	cout << endl;
 
    return 0;
}