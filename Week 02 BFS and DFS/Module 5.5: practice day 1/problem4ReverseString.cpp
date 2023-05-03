#include<iostream>
#include<vector>
#include<string>
using namespace std;


string reverse_string(string str)
{
    string new_string="";
    if (str=="")
    {
        return str;
    }
    return reverse_string(str.substr(1))+str[0];
    
}
int main()
{
    string str;
    cin>>str;

    str=reverse_string(str);
    cout<<str;

    return 0;
}