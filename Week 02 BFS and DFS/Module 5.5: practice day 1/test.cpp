#include <iostream>
using namespace std;

char getCapital(string str) {
    if (str[0] == '\0') {
        // Base case: end of string reached without finding capital letter
        return '\0';
    }
    if (isupper(str[0])) {
        // Base case: first letter is capital
        return str[0];
    }
    else {
        // Recursive case: continue searching in the rest of the string
        return getCapital(str.substr(1));
    }
}

int main() {
    string input_str = "aBcdEfG";
    char capital_letter = getCapital(input_str);
    if (capital_letter == '\0') {
        cout << "No capital letter found" << endl;
    }
    else {
        cout << "First capital letter found: " << capital_letter << endl;
    }
    return 0;
}
