#include <iostream>
using namespace std;

void Search(int arr[], int tar, int n, int i)
{

    if (i == n)
    {
        return;
    }

    if (arr[i] == tar)
    {
        cout << i << endl;
    }

    Search(arr, tar, n, i + 1);
}

int main()
{

    int arr[] = {1, 4, 2, 8, 2, 7, 2, 6, 2, 2, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    Search(arr, 2, n, 0);
    return 0;
}