#include <iostream>
#include <vector>
using namespace std;
int Mcm( vector<int> arr, int i, int j)
{

    if (i == j)
    {
        return 0;
    }
    int ans = INT16_MAX;

    for (int k = i; k < j; k++)
    {

        int count1 = Mcm(arr, i, k);
        int count2 = Mcm(arr, k + 1, j);

        int currCount = count1 + count2 + (arr[i - 1] * arr[k] * arr[j]);

        ans = min(ans, currCount);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 3};

    int n = arr.size();
    cout << Mcm(arr, 1, n - 1);
}