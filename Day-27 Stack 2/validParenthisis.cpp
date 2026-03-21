#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool validParenthisis(string str)
{
    stack<int> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '{' || ch == '[' || ch == '(')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            // match
            char top = s.top();
            if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}'))
            {

                s.pop();
            }
            else
            {

                return false;
            }
        }
    }
    return s.empty();
}

int main()
{

    string str1 = "{}";

    cout<<validParenthisis(str1);

    return 0;
}