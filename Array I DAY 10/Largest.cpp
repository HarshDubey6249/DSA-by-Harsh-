#include<iostream>
using namespace std;

int main(){
     int arr[]={222,34,54,22,12,34,22,432};
     int n=sizeof(arr)/sizeof(int);

     int max=0;
     for(int i=0;i<=n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
        cout<<"laegest element is ="<<max<<endl;

     }
     cout<<"---------------------"<<max<<"--------------------";
     return 0;
}