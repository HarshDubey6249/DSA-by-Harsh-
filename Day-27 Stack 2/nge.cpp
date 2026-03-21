#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void NextStep(vector<int> arr, vector<int> ans)
{

    stack<int> s;
    int n=arr.size();
    s.push(arr[n-1]);
    ans[n-1]=-1;

    for(int i=n-2;i>=0;i--){

        int curr=arr[i];

        while(!s.empty() && curr>=s.top()){
            s.pop();
        }
        if(s.empty()){

            ans[i]=-1;

        }else{
            ans[i]=s.top();
        }
        s.push(curr);
    }
 for (int i = 0; i < arr.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
}

int main()
{

    vector<int> arr = {6,8,0,1,3};
    vector<int> ans(arr.size(), 0);;

    NextStep(arr, ans);
    return 0;
}