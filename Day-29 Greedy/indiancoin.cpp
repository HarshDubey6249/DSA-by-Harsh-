#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void indianCoins( vector<int>coins,int v){
    int n=coins.size();
    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(v >=coins[i]){

            int coincount= v/coins[i];
            v=v%coins[i];
            ans+=coincount;
        }
    }
    cout<<ans;
}

int main(){
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    indianCoins(coins,1099);
    return 0;
}