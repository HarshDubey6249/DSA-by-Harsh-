// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[] = {10, 12,-13, 40, -50};
//     int n = 5;
//         int max=0;

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = i; j < n; j++)
//         {
//             int sum = 0;
//              // int max=0;
//             // cout<<"("<<i<<","<<j<<")";
//             for (int a = i; a <= j; a++)
//             {
//                 sum += arr[a];
//                 if(sum>max){
//                     max=sum;
//                 }

//             }
//             cout << sum;
//             cout << ",";

//         }

//         cout << endl;
//     }
//     cout<<"================="<<max<<"================";
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 12, -13, 40, -50};
    int n = 5;
    int max = INT16_MIN;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        int currentSum = 0;
        for (int j = i; j < n; j++)
        {
            currentSum += arr[j];
            if (currentSum > max)
            {
                max = currentSum;
            }
        }
    }
    cout << "=================" << max << "================";
    return 0;
}