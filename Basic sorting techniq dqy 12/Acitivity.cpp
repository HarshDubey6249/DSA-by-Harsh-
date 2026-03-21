#include<iostream>
using namespace std;
int InserShort(int *arr,int n){
 
  for(int i=1;i<n;i++){
    int curr=arr[i];
    int pre=i-1;

     while(pre>=0 && arr[pre]>curr){

        swap(arr[pre],arr[pre+1]);
        pre--;
     }

     arr[pre+1]=curr;
  }
    
}

int bubbleShort(int *arr,int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int selectionShort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int minIsx=i;

        for(int j=i;j<n;j++ ){

            if(arr[j]<arr[minIsx]){
                minIsx=j;
            }
        }
        swap(arr[i],arr[minIsx]);
    }

}

int count(int *arr,int n){

    int fre[1000000]={0};
    int minVal=INT16_MAX, maxVal=INT16_MIN;

    for(int i=0;i<n;i++){
        fre[arr[i]]++;
        maxVal=max(maxVal,arr[i]);
        minVal=min(minVal,arr[i]);

    }

    for(int i=minVal,j=0;j<maxVal;i++){
     while(fre[i]>0){
        arr[j++]=i;
        fre[i]--;

    }
}
}

int main()
{
    int arr[]={3,6,2,1,8,7,4,5,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
   // InserShort(arr,n);
  // bubbleShort(arr,n);
  selectionShort(arr,n);


     for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}