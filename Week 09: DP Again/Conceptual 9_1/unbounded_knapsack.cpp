#include<iostream>  
#include<vector>
using namespace std;

int max_possible_sum(vector<int> & ln, vector<int> & val, int size, int length)
{
    if (size==0 || length==0)
    {
        return 0;
    }
    
    if (ln[size-1]<=length)
    {
        return max(val[size-1]+max_possible_sum(ln, val, size, length-ln[size-1]), max_possible_sum(ln, val, size-1, length));
    }
    else
    {
        return max_possible_sum(ln, val, size-1, length);
    }
    
}

int main()
{
    int l;
    cin>>l;
    vector<int>ln(l), val(l);
    for(int i=0; i<l; i++)
    {
        ln[i]=i+1;
        cin>>val[i];
    }
    cout<<max_possible_sum(ln, val, l,l);
    return 0;
}