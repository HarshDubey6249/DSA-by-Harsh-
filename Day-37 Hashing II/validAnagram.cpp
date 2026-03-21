#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void valid(string s, string t)
{

    int n1 = s.size();
    int n2 = t.size();

    if (n1 != n2)
    {

        cout << "not valid anagram";
        return;
    }

    unordered_map<char, int> m;
    for (int i = 0; i < n1; i++)
    {
        if (m.count(s[i]))
        {

            m[s[i]]++;
        }
        else
        {

            m[s[i]] = 1;
        }
 }

 for(int i=0;i<t.size();i++){
    if (m.count(t[i]))
        {

            m[t[i]]--;
            if (m[t[i]] == 0)
            {
                m.erase(t[i]);
            }
        }
         
 }

    if (m.size() == 0)
    {
        cout << "valid anagram";
    }
    else
    {
        cout << "not valid anagram";
    }
}

int main()
{
    string s = "apple";
    string t = "plape";

    valid(s, t);
    return 0;
}