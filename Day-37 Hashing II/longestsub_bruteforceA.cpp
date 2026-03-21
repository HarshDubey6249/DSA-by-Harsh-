#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void longestSubofsum( vector<int> &arr){

    unordered_map<int,int>m;
    int ans=0;
    int sum=0;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];

        if(m.count(sum)){

            int length=i-m[sum];
            ans=max(ans,length);

        }else{

            m[sum]=i;
        }
    }
    cout<<"maximum length is = "<<ans;
}

int main()
{
    vector<int> arr= {15, -2, 2, -8, 1, 7, 10};
    longestSubofsum(arr);
    return 0;

   
}