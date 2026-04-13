#include <iostream>
#include <vector>
using namespace std;

int knapsakMemo(vector<int> val, vector<int> wt, int W, int n,vector<vector<int>> &dp)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    int weight = wt[n - 1];
    int kvalue = val[n - 1];

    if (weight <= W)
    {
        // include
        int ans1 = knapsakMemo(val, wt, W - weight, n - 1,dp) + kvalue;
        // exclude
        int ans2 = knapsakMemo(val, wt, W, n - 1,dp);

        dp[n][W]= max(ans1, ans2);
    }
    else
    {

        // exclude
       dp[n][W]= knapsakMemo(val, wt, W, n - 1,dp);
    }
    return dp[n][W];
}

int main()
{

    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;

    int n = val.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    cout << knapsakMemo(val, wt, W, n,dp);
    return 0;
}