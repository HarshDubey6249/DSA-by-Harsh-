#include<iostream>
using namespace std;

int main(){
    int n=153;
    int arm=0;
      int original = n;
    while(n>0){
    int digit=n%10;
    arm=arm+(digit*digit*digit);
    n/=10;
    }
    if(arm==original){
        cout<<"this armstong";
    }
    else{
        cout<<"it is not armstrong";
    }
    cout<<arm;

    return 0;
}
