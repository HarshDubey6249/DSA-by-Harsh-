#include<iostream>
using namespace std;

int diagonalSum(int mat[][4], int n, int m){
     int preSum=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                 cout<<mat[i][j]<<" ";
                 preSum+=mat[i][j];
            }
            else if (j==n-i-1)
            {
                 cout<<mat[i][j]<<" ";
                preSum+=mat[i][j];
            }
            
        }
        cout<<endl;
    }
    cout<<"primary sum"<<preSum;
}

int main(){
   int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int n = 4, m = 4;
   

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    diagonalSum(arr,4,4);

    return 0;
}