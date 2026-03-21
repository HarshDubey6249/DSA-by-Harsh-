#include<iostream>
using namespace std;

void bubble_short(int *arr,int n){

    for(int i=0;i<n-1;i++){

        bool isswap=false;
        for(int j=0;j < n-i-1;j++){

            if(arr[j]>arr[j+1]){

               swap(arr[j],arr[j+1]);
               isswap=true;
            }
            
        }
        if(!isswap){
            return ;
        }
    }
   
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8
};
    int n=sizeof(arr)/sizeof(arr[0]);
bubble_short(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;

}