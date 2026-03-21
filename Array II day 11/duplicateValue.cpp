#include<iostream>
using namespace std;

int duplicateVale(int *arr,int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
               cout<<"true";
                return true;
            }
             
            
          
        }
        
    }
    cout<<"false";
    return false;
}

int main(){
    int arr[]={1,2,3,4,4,5,6,7,8,8};
     int n=sizeof(arr)/sizeof(arr[0]);

    duplicateVale(arr,n);
}