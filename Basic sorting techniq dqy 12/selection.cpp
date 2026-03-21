#include<iostream>

using namespace std;

int selectionShort(int *arr,int n){

    for(int i=0;i<n-1;i++){

        int minIndx=i;

    for(int j=i;j<n;j++){

        if(arr[j]< arr[minIndx]){

            minIndx=j;
        }
    }
    swap(arr[i],arr[minIndx]);

    }
}

int main(){
    int arr[]={5,1,3,2,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionShort(arr,n);

     for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}