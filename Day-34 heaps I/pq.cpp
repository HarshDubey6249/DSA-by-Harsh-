#include<iostream>
#include<queue>
using namespace std;  


int main()
{
    priority_queue<int> pq; // Max-heap by default
     //priority_queue<int ,vector<int>, greater<int>> pq;  // Min-heap

    // Inserting elements into the priority queue
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);

    cout << "Elements in the priority queue (max-heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // Access the top element
        pq.pop(); // Remove the top element
    }
    cout << endl;

    return 0;
}