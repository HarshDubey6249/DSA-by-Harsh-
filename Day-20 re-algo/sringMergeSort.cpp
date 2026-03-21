#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(string arr[], int st, int mid, int end)
{
    vector<string> temp;
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

    for (int k = st, x = 0; k <= end; k++)
    {
        arr[k] = temp[x++];
    }
}

void mergesort(string arr[], int st, int end)
{
    if (st >= end)
        return;

    int mid = st + (end - st) / 2;

    mergesort(arr, st, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}

int main()
{
    string arr[] = {"sun", "earth", "mars", "mercury"};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
