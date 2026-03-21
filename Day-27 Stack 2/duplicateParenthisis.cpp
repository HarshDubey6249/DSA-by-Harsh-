#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dunlicateP(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (ch != ')')
        {
            s.push(ch);
        }
        else
        {
            if (s.top() == '(')
            {

                return true;
            }
            
            

                while (s.top() != '(')
                {
                    s.pop();
                }
                s.pop();
            
        }
    }
        return false;
    
}

int main()
{

    string str1 = "((a+b))";
    string str2 = "((a+b)+(a+b))";

    cout << dunlicateP(str1);

    return 0;
}