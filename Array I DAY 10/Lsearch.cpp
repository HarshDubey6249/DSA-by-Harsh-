#include<iostream>
using namespace std;
int main(){
     int arr[]={222,34,54,22,12,34,22,432};
     int n=sizeof(arr)/sizeof(int);
     int tar=12;

     for( int i=0;i<n;i++){
       if(tar==arr[i]){
        cout<<"we found ele in index"<<i <<endl;
    
       }
       }
      
    
     return 0;
}