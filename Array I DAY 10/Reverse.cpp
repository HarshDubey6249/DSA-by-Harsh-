#include<iostream>
using namespace std;
int main(){
     int arr[]={222,34,54,22,12,34,22,432};
     int n=sizeof(arr)/sizeof(int);
     int start=0;
     int end=n-1;
     while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
     }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
     }
    

    
      
    
     return 0;
}