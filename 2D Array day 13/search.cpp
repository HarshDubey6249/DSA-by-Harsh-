#include<iostream>
using namespace std;
int binarS(int arr[][4], int n, int m, int key) {
    int start = 0;
    int end = n * m - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int row = mid / m;
        int col = mid % m;
        if (arr[row][col] == key) {
            cout << "Found at index (" << row << ", " << col << ")\n";
            return 1;
        }
        if (arr[row][col] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << "Not found\n";
    return -1;
}
// int binarSleft(int arr[][4], int n, int m, int key){
//     int i=0;
//     int j=m-1;
//          while(i<n&&j>=0){
//         int cell=arr[i][j];
//         if(cell=key){
//             return true;
//         }
//         else if(cell>key){
//             j--;
//         }
//         else{
//             i++;
//         }
//     }
//     return false;
// }

int binarSright(int arr[][4], int n, int m, int key){
    int i=n-1;
    int j=0;
         while(j<m&&i>=0){
        int cell=arr[i][j];
        if(cell==key){
            cout<<"("<<i<<","<<j<<")";
            return true;
        }
        else if(cell>key){
            i--;
        }
        else{
            j++;
        }
    }
    return false;
}


int main(){
    int arr[4][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
    int n = 4, m = 4;
    int key=11;
    cout<<binarSright(arr,4,4,key);

    return 0;
}