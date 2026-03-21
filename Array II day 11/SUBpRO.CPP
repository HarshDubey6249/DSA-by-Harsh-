#include <iostream>
using namespace std;

void kandan(int *arr, int n)
{

    int maxpro = INT16_MIN;
    int currentpro = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            for (int sub = i; sub <= j; sub++)
            {
                //  cout<<arr[sub];
                currentpro *= arr[sub];
            }
            if (currentpro > maxpro)
            {
                maxpro = currentpro;
            }
            cout << ",";
        }
        cout << endl;
    };
    cout << maxpro;
}

int main()
{
    int arr[] = {-2, 0, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    kandan(arr, n);

    return 0;
}