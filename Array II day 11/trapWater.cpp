#include <iostream>
#include <algorithm>
using namespace std;

int trapWater(int *height, int n) {

    int leftMax[20000], rightMax[20000];

    // Build leftMax
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Build rightMax
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Calculate trapped water
    int trapWaterSum = 0;
    for (int i = 0; i < n; i++) {
        int minBar = min(leftMax[i], rightMax[i]) - height[i];
        if (minBar > 0)
            trapWaterSum += minBar;
    }

    return trapWaterSum;
}

int main() {
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Trapped Water = " << trapWater(arr, n);
}

