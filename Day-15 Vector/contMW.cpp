#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>  Container_With_Most_Water(vector<int> nums)
{
    int left=0;
    int right=nums.size()-1;
    int maxarea=0;

    // int rightMax=INT16_MIN;
    // int leftMax=INT16_MIN;

    while(left<right){
        int width=right-left;

        int h=min(nums[left],nums[right]);

        int area=h*width;

        maxarea=max(maxarea,area);

        if(nums[left]>nums[right]){
            right--;
        }
        else{
            left++;
        }
    }
    cout<<maxarea;
    

}

int main()
{

    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};

      Container_With_Most_Water(nums);
  

    return 0;
}