#include<iostream>
#include<vector>
using namespace std;

int countWaysUsingRecursion(int n,vector<int>&vec){

 vec[0]=1;
 vec[1]=1;



 for(int i=2;i<n+1;i++){
    vec[i]=vec[i-1]+vec[i-2];
 }

 return vec[n];
 
}

int main(){
    int n=5;
    vector<int>vec(n+1,-1);
    cout<<countWaysUsingRecursion(n,vec);
    return 0;
}