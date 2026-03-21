#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> pairSum(vector<int> nums,int target){

    sort(nums.begin(),nums.end());

    int st=0;
    int end=nums.size()-1;
 int  sum=0;
    vector<int> ans;

    while(st<end){
        sum=nums[st]+nums[end];

      if(sum==target){
        ans.push_back(nums[st]);
        ans.push_back(nums[end]);
        return ans;
      }
      else if(sum>target){
        end--;
      }else{
            st++;
      }
    }
 return ans;
}

int main(){

    vector<int> nums={2,4,1,5,7,4,8};
   vector<int> ans=pairSum(nums,9);

   cout<<"pair sum is ("<<ans[0]<<","<<ans[1]<<"}";
    return 0;

}