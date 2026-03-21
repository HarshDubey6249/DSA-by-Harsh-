#include <iostream>
#include<queue>
using namespace std;

class Stack{

    queue<int>q1;
    queue<int>q2;
public:
    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

         while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){
        if (empty()) {
            cout << "Queue is empty\n";
            return ;
        }

         q1.pop();
    }
   

    int top(){
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

      return  q1.front();
    }

    bool empty(){
        return q1.empty();
    }



};

int main(){

    Stack s;

    s.push(2);
    s.push(4);
    s.push(6);

    cout << "Top: " << s.top() << endl;
    cout << "======================" << endl;

    s.pop();

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }








    return 0;
}