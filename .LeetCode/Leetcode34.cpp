#include<iostream>
using namespace std;

int find_first(int *arr,int n,int tar){

    int st=0;
    int end=n-1;
    int ans=-1;

    
    while(st<=end){

        int mid=(st+end)/2;

        if(arr[mid]==tar){
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]> tar){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
        
    }
  return ans;
}

int _last_position(int *arr,int n,int tar){

    int st=0;
    int end=n-1;
    int ans=-1;

    
    while(st<=end){

        int mid=(st+end)/2;

        if(arr[mid]==tar){
            ans=mid;
            st=mid+1;
        }
        else if(arr[mid]> tar){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
        
    }
  return ans;
}

int main(){
    int arr[]={5,7,7,8,8,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    int ne=find_first(arr,n,8);
    int me=_last_position(arr,n,8);
    cout<<ne;
    cout<<me;
    return 0;
}
