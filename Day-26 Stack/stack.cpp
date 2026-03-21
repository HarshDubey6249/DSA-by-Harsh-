#include <iostream>
#include <vector>
using namespace std;

template <class R>
class Stack
{

    vector<R> vec;

 public:
    void push(int val)
    {

        vec.push_back(val);
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return;
        }

        vec.pop_back();
    }

   R top()
    {

        if (isEmpty())
        {
            cout << "stack is empty";
            return false;
        }
        int idx = vec.size() - 1;

        return vec[idx];
    }

    bool isEmpty()
    {
        return vec.size() == 0;
    }
   void print(){
    while(!isEmpty()){

        cout<<top()<<"--";
        pop();

    }
    }


    
};

int main()
{
    Stack<int> s;

    s.push(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.print();
 

    return 0;
}