#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void longestSubofsum(vector<int> &arr, int k)
{
   unordered_map<int, int> m;
    int ans = 0;
    int sum = 0;
     m[0] = 1;

    for (int i = 0; i < arr.size(); i++)
    {
         sum+=arr[i];
        if (m.count(sum -k))
        {

            ans += m[sum - k];
        }
        
        if(m.count(sum)){
            m[sum]++;
        }
        else{
            m[sum]=1;
        }
    }
    cout << "maximum length is = " << ans;
}

int main()
{
    vector<int> arr = {10,2,-2,-20,10};
    longestSubofsum(arr,-10);
    return 0;
}