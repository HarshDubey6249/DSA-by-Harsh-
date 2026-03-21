#include <iostream>
#include <list>
#include<stack>
using namespace std;

template <class R>
class Node
{
  public:
    R data;
    Node *next;

    Node(R val)
    {
        data = val;
        next = NULL;
    }
};

template <class R>
class Stack
{
public:
 Node<R>* head;

 Stack()
{
    head = NULL;
}


    void push(R val)
{
    Node<R>* newnode = new Node<R>(val);
    newnode->next = head;
    head = newnode;
}


    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }else{

        Node<R>* temp = head;
        head = head->next;
        delete temp;
        }
    }

    R top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return R(); // default value
        }
        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    // void print()
    // {
    //     while (!isempty())
    //     {
    //         cout << top() << " -> ";
    //         pop();
    //     }
    //     cout << "NULL\n";
    // }
};

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

    cout << "Stack elements (top to bottom): ";

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }


    return 0;
}
