//string recursion

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool is_palindrom(string s)
{
    if (s=="" || s.size()==1)
    {
        return true;
    }
    int n=s.size();
    string sub_string=s.substr(1, n-2);
    return (is_palindrom(sub_string) && s[0]==s.back());
}
int main()
{
    string s;
    cin>>s;
    if (is_palindrom(s))
    {
        cout<<"yes";
    }
    else 
        cout<<"No";
    
    return 0;
}