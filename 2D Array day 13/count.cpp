#include<iostream>
using namespace std;

int count( int arr[][4],int n,int m,int key){

    int cut=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==key){

                cut++;
               
            }
        }
    }
    
    return cut;
}

int main(){
    int arr[4][4] = {{1, 11, 3, 4},{5, 11, 7, 8},{9, 10, 11, 12},{13, 11, 15, 16}};
    int n = 4, m = 4;
    int key=11;
    cout<<count(arr,4,4,key);

    return 0;
}