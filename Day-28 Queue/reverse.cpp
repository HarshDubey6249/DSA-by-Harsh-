#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reversr(queue<int> &q)
{

    int n = q.size();
    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
int main()
{
    queue<int> q;

    for (int i = 1; i <= 10;i++)
    {
        q.push(i);
    }
    
    cout<<"============================";

    reversr(q);
    for (int i = 1; i <= 10; i++)
    {
        cout << q.front()<<" ";
        q.pop();
    }
    cout << endl;
}
