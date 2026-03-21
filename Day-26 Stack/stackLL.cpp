#include <iostream>
#include <list>
using namespace std;

template <class R>
class Stack
{
    list<R> ll;

public:
    void push(R val)
    {
        ll.push_front(val);   // push at top
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        ll.pop_front();
    }

    R top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return R();   // default value
        }
        return ll.front();
    }

    bool isEmpty()
    {
        return ll.empty();
    }

    void print()
    {
        while (!isEmpty())
        {
            cout << top() << " -> ";
            pop();
        }
        cout << "NULL\n";
    }
};

int main()
{
    Stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);

    s.print();   // empties stack
    s.pop();     // stack already empty
    s.print();

    return 0;
}
