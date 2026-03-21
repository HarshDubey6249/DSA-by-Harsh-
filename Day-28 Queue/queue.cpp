#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int dat)
    {
        data = dat;
        next = NULL;
    }
};

class Queue
{

    Node *head;
    Node *tail;

public:


    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int dat)
    {

        Node *newnode = new Node(dat);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop()
    {

        if (empty())
        {
            cout << "Queue is empty";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue is empty";
            return -1;
        }

        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{

    Queue q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
