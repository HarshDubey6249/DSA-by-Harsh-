#include<iostream>
using namespace std;
class Parent{
    public:
        void show()
        {
            cout << "I am parent class show function" << endl;
        }

        virtual void hello(){
            cout<<"Hello fun";
        }
};

class child : public Parent{
    public:
        void show()
        {
            cout << "I am child class show function" << endl;
        }

        void hello(){
            cout<<" child Hello fun";
        }
};
int main(){
    child c1;
    parent *ptr;
    
    ptr=&c1;// run time binding

    ptr->hello(); //virtual function
    return 0;
}