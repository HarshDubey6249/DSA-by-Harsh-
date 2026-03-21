#include <iostream>
using namespace std;

void permutation(string str, string ans)
{
    int n = str.size();

    if (n == 0)
    {
        cout << ans << endl;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        string strnnest = str.substr(0, i) + str.substr(i + 1, n - i - 1);
        permutation(strnnest, ans + ch);
    }
}
int main()
{
    string str = "abcd";
    string ans = "";
    permutation(str, ans);
    cout << ans.size() << endl;
    return 0;
}