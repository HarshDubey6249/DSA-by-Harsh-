#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int TrapWater(vector<int> arr)
{
    int n = arr.size();
    if (n == 0) return 0;

    stack<int> right;
    stack<int> left;

    // Build prefix max (right stack)
    right.push(arr[0]);
    for (int i = 1; i < n; i++) {
        int rightval = max(right.top(), arr[i]);   // FIXED
        right.push(rightval);
    }

    // Build suffix max (left stack)
    left.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        int leftval = max(left.top(), arr[i]);     // FIXED
        left.push(leftval);                        // FIXED
    }

    int trapWaterSum = 0;
    int i = 0;

    while (!left.empty() && !right.empty() && i < n) {
        int minBar = min(left.top(), right.top()) - arr[i];

        if (minBar > 0)
            trapWaterSum += minBar;

        left.pop();
        right.pop();
        i++;
    }

    return trapWaterSum;
}

int main()
{

   vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};

   cout<<"trap water ="<<TrapWater(arr);

    return 0;
}