#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>arr,int tar)

{
     //sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){

                if(arr[i]+arr[j]+arr[k]==tar){
                     
                    ans.push_back({arr[i], arr[j], arr[k]});
                }
    

            }
        }
    }
    return ans;

}
int main(){

     vector<int> arr = {-1, 0, 1, 2, -1, -4};

     vector<vector<int>> ans= threeSum(arr,0);

     for(auto && tri :ans){
        cout<<"["<<tri[0]<<","<<tri[1]<<","<<tri[2]<<"]";
     }
     return 0;
}