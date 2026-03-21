#include <iostream>
using namespace std;

void kandan(int *arr, int n)
{

    int maxSum = INT16_MIN;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    cout << "=================" << maxSum << "================";
}

int main()
{
    int arr[] = {-3, -4, 5, 9, 10, -1, -2, 11};
    int n = 8;
    kandan(arr, n);

    return 0;
}