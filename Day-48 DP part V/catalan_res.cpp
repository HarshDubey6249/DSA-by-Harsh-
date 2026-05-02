#include <iostream>
#include <vector>
using namespace std;
int catalonRes(int n)
{

    if (n == 0 || n == 1)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        ans += catalonRes(i) * catalonRes(n - i - 1);
    }
    return ans;
}

int catalonMemo(int n, vector<int> dp)
{

    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        ans += catalonMemo(i, dp) * catalonMemo(n - i - 1, dp);
    };

    return dp[n] = ans;
}

int catlanTabulation(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main()
{
    int n = 4;

   // vector<int> dp(n + 1, -1);
    for (int i = 0; i <= n; i++)
    {
        cout << catlanTabulation(i) << " ";
    }
}
