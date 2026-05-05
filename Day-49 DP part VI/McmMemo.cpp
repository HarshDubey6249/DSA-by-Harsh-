#include <iostream>
#include <vector>
using namespace std;
int Mcm( vector<int> arr, int i, int j,vector<vector<int>>&dp)
{

    if (i == j)
    {
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT16_MAX;

    for (int k = i; k < j; k++)
    {

        int count1 = Mcm(arr, i, k,dp);
        int count2 = Mcm(arr, k + 1, j,dp);

        int currCount = count1 + count2 + (arr[i - 1] * arr[k] * arr[j]);

        ans = min(ans, currCount);
    }
    return dp[i][j]=ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 3};

    int n = arr.size();


    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout << Mcm(arr, 1, n - 1,dp);
}