#include<iostream>
using namespace std;

void sellBye(int *arr,int n){
    int byPrice[100000];
    byPrice[0]=INT16_MAX;
    for(int i=1;i<n;i++){
    byPrice[i]=min(byPrice[i-1],arr[i-1]);
    }

    int maxProfit=0;
    for(int i=0;i<n;i++){
    int currentPrice= arr[i]-byPrice[i];
    maxProfit=max(maxProfit,currentPrice);
    }
    cout<<"max profit is="<<maxProfit;


}

int main(){
  int  arr[]={7,5,2,1,11,2,12};
  int n=sizeof(arr)/sizeof(arr[0]);
  sellBye(arr,n);
}