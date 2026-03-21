#include <iostream>
using namespace std;

class Queue
{

    int *arr;

    int capacity;
    int currSize;
    int f; // front;
    int r; // rear;

public:
    Queue(int n)
    {

        capacity = n;
        currSize = 0;

        arr = new int[n];
        f = 0;
        r = -1;
    }
     ~Queue() {
        delete[] arr;
    }
    void push(int data)
    {
        if (currSize == capacity)
        {
            cout << "Queue is full \n";
            return;
        }

        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }
    void pop()
    {
        if (empty())
        {
           cout << "Queue is empty\n";
            return;
        }
        f = (f + 1) % capacity;
        currSize--;
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }
};

int main()
{
    Queue q(4);

    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.front()<<endl;
    q.pop();
    q.push(6);
    cout << q.front()<<endl;;
    q.pop();
    q.push(5);

    return 0;
}