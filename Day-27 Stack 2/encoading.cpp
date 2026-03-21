#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

string decodeString(string s) {
    stack<int> numStack;        // Stack for numbers
    stack<string> strStack;     // Stack for strings
    string curr = "";           // Current decoded string
    int num = 0;                // Current number

    for (char ch : s) {
        if (isdigit(ch)) {
            // Build the number (handles multi-digit numbers)
            num = num * 10 + (ch - '0');
        } 
        else if (ch == '[') {
            // Push current state into stacks
            numStack.push(num);
            strStack.push(curr);
            num = 0;
            curr = "";
        } 
        else if (ch == ']') {
            int repeat = numStack.top();
            numStack.pop();

            string temp = curr;
            curr = strStack.top();
            strStack.pop();

            // Repeat temp 'repeat' times
            while (repeat--) {
                curr += temp;
            }
        } 
        else {
            // Normal character
            curr += ch;
        }
    }

    return curr;
}

int main() {
    string s = "3[a2[c]]";
    cout << decodeString(s);
    return 0;
}
