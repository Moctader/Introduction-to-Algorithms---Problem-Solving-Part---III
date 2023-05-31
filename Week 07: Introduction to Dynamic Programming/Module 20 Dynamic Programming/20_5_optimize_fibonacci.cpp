#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll ara[101];

ll fib(int x)
{
    if (x<=2)
    {
        return 1;
    }
    if (ara[x] !=0)
    {
        return ara[x];
    }
    ara[x]=fib(x-1)+fib(x-2);
    return ara[x];
    
    
}

int main()
{
    cout<<fib(7)<<endl;

    return 0;
}