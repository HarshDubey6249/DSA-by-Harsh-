#include<iostream>
using namespace std;

int binart_to_decimal(int num){
    int n=num;
    int pow=1;
    int ans=0;

    while(n>0){
        int lastdig=n%2;
        ans=ans+lastdig*pow;
        pow=pow*10;
        n=n/2;
    }
    return ans;
}

int main(){
    int arr[]={11,10,25,29,31,88};
      int size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<size;i++){
    cout<<binart_to_decimal(arr[i])<<endl;
    }
    
    return 0;
}