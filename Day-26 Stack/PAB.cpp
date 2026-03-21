// Push At Bottom

#include <iostream>
#include <stack>
using namespace std;

void PAB(stack<int> &s, int value)
{

    if (s.empty())
    {

        s.push(value);
        return;
    }
    int temp = s.top();
    s.pop();

    PAB(s, value);
    s.push(temp);
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
 
    
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    reverse(s);

    cout << "Stack elements (top to bottom): ";

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}