#include <iostream>
#include <string>
using namespace std;
void removeDuplicate(string str, int map[26], string ans, int i)
{

    if (i == str.size())
    {
        cout << ans << endl;
        return;
    }
    char ch = str[i];
    int mapIdx = (int)(ch - 'a');

    if (map[mapIdx])
    {

        removeDuplicate(str, map, ans, i + 1);
    }
    else
    {
        map[mapIdx] = true;
        removeDuplicate(str, map, ans + str[i], i + 1);
    }
}
int main()
{
    string str = "appnnacollegeco";
    string ans = "";
    int map[26] = {false};

    removeDuplicate(str, map, ans, 0);
    return 0;
}