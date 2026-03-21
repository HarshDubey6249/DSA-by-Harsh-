#include<iostream>
using namespace std;
int sum( int arr[][4],int n,int m){
    int cut=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==1){

                cut+=arr[i][j];
                }
        }
    }
    return cut;
}
int main(){
    int arr[4][4] = {{1, 11, 3, 4},{5, 11, 7, 8},{9, 10, 11, 12},{13, 11, 15, 16}};
    int n = 4, m = 4;
   
    cout<<sum(arr,4,4);
    return 0;
}