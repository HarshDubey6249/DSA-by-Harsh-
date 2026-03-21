#include<iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);

    int st = 0;
    int end = n - 1;
    int tar = 7;

    while(st <= end) {
       int mid = st + (end - st) / 2;


        if(arr[mid] == tar) {  
            cout << "Target found at index " << mid;
            return 0; // stop after finding
        }
        else if(arr[mid] > tar) {
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }

    cout << "Target not found";

    return 0;
}
