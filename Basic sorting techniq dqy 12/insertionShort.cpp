#include<iostream>

using namespace std;

int InserShort(int *arr,int n){

    for(int i=1;i<n;i++){

        int currValue=arr[i];
       int pre=i-1;

    while(pre>=0&& arr[pre]>currValue){
        swap(arr[pre],arr[pre+1]);
        pre--;
   }
   arr[pre+1]=currValue;
   

    }
}

int main(){
    int arr[]={5,1,3,2,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    InserShort(arr,n);

     for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}