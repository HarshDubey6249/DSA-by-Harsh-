#include<iostream>
using namespace std;

void charShort(char arr[],int n){

    for(int i=1;i<n;i++){

    int currValue=arr[i];
    int pre=i-1;
    while (pre>=0 && arr[pre]>currValue)
    {
       swap(arr[pre],arr[pre+1]);
       pre--;
    }
    arr[pre+1]=currValue;
    
    }



}
int main(){
   char arr[]={'q','w','g','m','f'};
      int n=sizeof(arr)/sizeof(arr[0]);
    charShort(arr,n);

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" '";
    }

}