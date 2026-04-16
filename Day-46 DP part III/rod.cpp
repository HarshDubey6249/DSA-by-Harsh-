#include <iostream>
#include <vector>
using namespace std;

int rod(vector<int> price, vector<int> lenght, int rodLength, int n)
{

    vector<vector<long long>> dp(n + 1, vector<long long>(rodLength + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= rodLength; j++)
        {

            if (lenght[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j - lenght[i - 1]] + price[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][rodLength];
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLength = 8;
    int n = 8;

    cout << rod(price, length, rodLength, n);

    return 0;
}