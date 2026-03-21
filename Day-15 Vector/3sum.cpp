#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> nums, int target)
{

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {

            long long  sum = nums[i] + nums[j] + nums[k];

            if (sum < target)
            {
                j++;
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
               
                ans.push_back({nums[i], nums[j], nums[k]});

                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}
int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

vector<vector<int>> ans = threeSum(nums, 0);

for (auto && triplet : ans) {
    cout << "[" << triplet[0] << ", " 
                << triplet[1] << ", " 
                << triplet[2] << "]\n";
}


    return 0;
}