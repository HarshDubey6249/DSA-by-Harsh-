#include <iostream>
using namespace std;

void substring(string str, string subset)
{

    if (str.size() == 0)
    {
        cout << subset << endl;
        return;
    }

    char ch = str[0];
    // yes
    substring(str.substr(1, str.size() - 1), subset + ch);
    // no
    substring(str.substr(1, str.size() - 1), subset);
}
int main()
{
    string str = "abcd";
    string subset = "";
    substring(str, subset);
    return 0;
}