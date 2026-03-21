#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int st, int end, int mid)
{
    vector<int> temp;
    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for (int idx = st, x = 0; idx <= end; idx++)
    {
        arr[idx] = temp[x++];
    }
}

void mergeShort(int arr[], int st, int end)
{
    if (st >= end)
    {
        return;
    }
    int mid = st + (end - st) / 2;

    mergeShort(arr, st, mid);      // left
    mergeShort(arr, mid + 1, end); // right

    merge(arr, st, end, mid);
}

int print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {5, 1, 8, 2, 7, 3, 0, 1, 5, 3, 7, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeShort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}