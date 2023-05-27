#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

bool is_palindrom( string s)
{

    unordered_map<char, int> Num_char;

    for(auto ch:s)
    {
        Num_char[ch]++;
    }
    int odd=0;

    for(auto values:Num_char)
    {
        if (values.second % 2!=0)
        {
            odd++;
        }
        
    }

    if(odd<=1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    string input;
    cin>>input;
    if (is_palindrom(input))
    {
        cout<<"YES"<<endl;
    }
    else
   {
        cout<<"NO"<<endl;
   } 
    
    return 0;
}