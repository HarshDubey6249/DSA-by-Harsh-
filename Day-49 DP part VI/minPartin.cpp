#include <iostream>
#include <vector>
using namespace std;

int MInPartioning(vector<int> arr)
{
    int sum = 0;

    for (int el : arr)
    {
        sum += el;
    }

    int n = arr.size();
    int w = sum / 2;

    vector < vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = max(arr[i - 1] + dp[i - 1][j - arr[i - 1]], dp[i - 1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    int group1=dp[n][w];
    int g2=sum-group1;

    return abs(group1-g2);
}
int main()
{
    vector<int> arr = {1, 6, 11, 5};

    cout<<MInPartioning(arr)<<endl;
    return 0;
}