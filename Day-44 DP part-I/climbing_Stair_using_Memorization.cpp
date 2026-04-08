#include<iostream>
#include<vector>
using namespace std;

int countWaysUsingRecursion(int n,vector<int>&vec){

    if(n==0 || n==1){
        return 1;
    }
    if(vec[n]!=-1){
        return vec[n];

    }

   vec[n]= countWaysUsingRecursion(n-1,vec)+countWaysUsingRecursion(n-2,vec);
   return vec[n];
}

int main(){
    int n=5;
    vector<int>vec(n+1,-1);
    cout<<countWaysUsingRecursion(n,vec);
    return 0;
}