#include <iostream>
#include <vector>
using namespace std;

int knapsak(vector<int> val, vector<int> wt, int W, int n)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }
    int weight = wt[n - 1];
    int kvalue = val[n - 1];

    if (weight <= W)
    {
        // include
        int ans1 = knapsak(val, wt, W - weight, n - 1) + kvalue;
        // exclude
        int ans2 = knapsak(val, wt, W, n - 1);

        return max(ans1, ans2);
    }
    else
    {

        // exclude
        return knapsak(val, wt, W, n - 1);
    }
}

int main()
{

    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;

    int n = val.size();
    cout << knapsak(val, wt, W, n);
    return 0;
}