#include<iostream>
#include<vector>
using namespace std;

char getCapital(string str)
{
    if (str[0]=='\0')
    {
        return '\0';
    }

    if (isupper(str[0])) 
    {
        // Base case: first letter is capital
        return str[0];
    }
    
    else
    {
        return getCapital(str.substr(1));
    }
}

int main()
{
    string str;
    cin>>str;
    char capital_letter = getCapital(str);
    if (capital_letter == '\0') {
        cout << "No capital letter found" << endl;
    }
    else {
        cout << "First capital letter found: " << capital_letter << endl;
    }
    return 0;
}