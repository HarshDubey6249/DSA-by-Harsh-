#include<iostream>
using namespace std;
int transpose(int arr[][4],int n,int m){
 int transpose[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            transpose[j][i]=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
         cout<<   transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[4][4] = {{1, 11, 3, 4},{5, 11, 7, 8},{1, 11, 3, 4}};
    int n = 3, m = 4;
   transpose(arr,n,m);
    
    return 0;
}