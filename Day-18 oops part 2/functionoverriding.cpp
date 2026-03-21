#include<iostream>
using namespace std;
class parent{
    public:
        void show()
        {
            cout << "I am parent class show function" << endl;
        }
};

class child : public parent{
    public:
        void show()
        {
            cout << "I am child class show function" << endl;
        }
};
int main(){
    child c1;
    c1.show();
    return 0;
}