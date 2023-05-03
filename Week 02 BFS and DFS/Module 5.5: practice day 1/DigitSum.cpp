#include<iostream>
#include<vector>

using namespace std;

int  digitSum(int n)
{
    if (n==0)
    {
        return 0;
    }
    return (n%10+digitSum(n/10));
    
}

int main()
{
    int n;
    cin>>n;
    int result=digitSum(n);
    cout<<result;
    return 0;
}