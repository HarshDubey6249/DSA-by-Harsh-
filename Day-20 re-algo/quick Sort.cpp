#include <iostream>
#include <vector>
using namespace std;

int partition(int arr[], int st, int end)
{
    int i = st - 1;
    int j = st;
    int p = end;

    for (int j = st; j < end; j++)
    {
        if (arr[j] < arr[p])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[p]);

    return i;
}

void Quick_sort(int arr[], int st, int end)
{

    if (st >= end)
    {
        return;
    }

    int pivotIndex = partition(arr, st, end);
    Quick_sort(arr, st, pivotIndex - 1);
    Quick_sort(arr, pivotIndex + 1, end);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {8, 2, 7, 3, 0, 1, 5, 3, 7, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Quick_sort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}