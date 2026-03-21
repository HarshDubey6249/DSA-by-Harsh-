#include <iostream>
#include <string>
using namespace std;

class Print
{
public:
    void show(int x)
    {
        cout << "int:" << x << endl;
    }

    void show(string str)
    {
        cout << "str:" << str << endl;
    }
};

int main()
{
    Print ob1;
    ob1.show(25);
    ob1.show("harsh dubey");

    return 0;
}