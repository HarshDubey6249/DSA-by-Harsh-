#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{

    vector<int> arr = {2, 4, 3, 6};
    unordered_map<int, int> m;
    int tar = 6;

    for (int i = 0; i < arr.size(); i++)
    {
        int comp = tar - arr[i];
        if (m.count(comp))
        {

            cout << "[" << m[comp]<<"," << i << "]";
        }
        m[arr[i]] = i;
    }
}