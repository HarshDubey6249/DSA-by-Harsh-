#include<iostream>
#include<vector>
using namespace std;

int countWaysUsingRecursion(int n){

    if(n==0 || n==1){
        return 1;
    }

    return  countWaysUsingRecursion(n-1)+countWaysUsingRecursion(n-2);
}

int main(){
    int n=5;
    cout<<countWaysUsingRecursion(n);
    return 0;
}