#include <iostream>
using namespace std;

int roatedSortedArray(int arr[], int st, int end, int tar)
{

    if (st > end)
    {
        return -1;
    }

    int mid = st + (end - st) / 2;
    if (arr[mid] == tar)
    {
        return mid;
    }

    if (arr[st] <= arr[mid])
    {
        if (tar >= arr[st] && tar <= arr[mid])
        {
            return roatedSortedArray(arr, st, mid - 1, tar);
        }
        else
        {
            return roatedSortedArray(arr, mid + 1, end, tar);
            ;
        }
    }
    else
    {
        if (tar >= arr[mid] && tar <= arr[end])
        {
            return roatedSortedArray(arr, mid + 1, end, tar);
        }
        else
        {
            return roatedSortedArray(arr, st, mid - 1, tar);
        }
    }
}

int main()
{
    int arrr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arrr) / sizeof(arrr[0]);
    cout << roatedSortedArray(arrr, 0, n - 1, 0) << endl;
}