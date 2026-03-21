#include<iostream>

using namespace std;

int countShort(int *arr,int n){

    int freq[100000]={0};
    int minValue=INT16_MAX, maxValue=INT16_MIN;


    for(int i=0;i<n;i++){

       freq[arr[i]]++;
     minValue=min(minValue,arr[i]);
       maxValue=max(maxValue,arr[i]);
    }

    for(int i=minValue,j=0;i<=maxValue;i++){

        while (freq[i]>0)
           
        {
            arr[j++]=i;
            freq[i]--;
        }

         
}
}

int main(){
    int arr[]={5,1,3,1,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    countShort(arr,n);

     for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}