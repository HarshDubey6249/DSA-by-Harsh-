#include <iostream>
using namespace std;

int Binarysearch(int arr[], int st, int end, int tar)
{
    // Base case
    if (st > end)
    {
        return -1;
    }

    int mid = (st + end) / 2;

    if (arr[mid] == tar)
    {
        return mid;
    }
    else if (tar < arr[mid])
    {
        return Binarysearch(arr, st, mid - 1, tar);
    }
    else
    {
        return Binarysearch(arr, mid + 1, end, tar);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = Binarysearch(arr, 0, n - 1, 5);
    cout << result;

    return 0;
}
