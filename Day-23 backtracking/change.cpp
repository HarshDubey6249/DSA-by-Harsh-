#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void change(int arr[], int n, int i = 0)
{
    if (i == n)
    {
        print(arr, n);
        return;
    }

    arr[i] = i + 1;
    change(arr, n, i + 1);
    arr[i] -= 2;
}
int main()
{
    int arr[5] = {0};
    int n = 5;

    change(arr, n, 0);
    print(arr, n);
}