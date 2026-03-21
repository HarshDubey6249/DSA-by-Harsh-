// Given the head of a singly linked list, return true if it is a Palindrome or false otherwise.

#include <iostream>
#include <list>
#include <stack>
using namespace std;

bool palin(list<int> l)
{
    stack<int> s;

    for (int x : l)
    {
        s.push(x);
    }

    for (int x : l)
    {
        if (x != s.top())
        {
            return false;
        }
        s.pop();
    }

    return true;
}

int main()
{
    list<int> l = {1, 1, 2, 1};
    int pali = palin(l);

    if (pali)
    {
        cout << "palin";
    }
    else
    {
        cout << "not pain";
    }
    return 0;
}