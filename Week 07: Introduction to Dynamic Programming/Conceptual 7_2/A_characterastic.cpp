/*
Consider an array a1, a2, a3...an consisting of numbers 1 and -1 define a characterastic
of this array as a number of pairs of indices, such as ai.aj=1.
Find any array a with given length n with A characterastic equal to given value k


*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int>d;
    for(int i=0; i<n; i++)
    {
        d.push_back(1);
    }
    int positive=n, negative=0, totall=0;

    for(int i=0; i<n; i++)
    {
        totall=(positive*(positive-1))/2+(negative*(negative-1))/2;
        if (totall==k)
        {
            break;
        }
        d[i] *=-1;
        positive--;
        negative++;
    }

    if (totall==k)
    {
        cout<<"YES"<<endl;
        for(auto val:d)
        {
            cout<<val<<" ";
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}