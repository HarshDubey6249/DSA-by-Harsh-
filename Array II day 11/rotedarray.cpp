#include <iostream>
using namespace std;

int rotedSubArray(int *arr, int n, int tar)
{
    int low = 0;
    int high = n - 1;
    if (low < high)
    {
        return -1;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == tar)
        {
            return mid;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= tar && arr[mid] > tar)
            {

                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        else
        {
            if (arr[high] >= arr[mid] && arr[mid] < tar)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
}

int main()
{

    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << rotedSubArray(arr, n, 1);
}