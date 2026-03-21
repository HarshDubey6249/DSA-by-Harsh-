#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void mincost( vector<int> ropes){

    priority_queue<int ,vector<int>,greater<int>> pq (ropes.begin(),ropes.end());
int ans=0;
while(pq.size()>1){

  int min1=  pq.top();
  pq.pop();
  int min2=  pq.top();
  pq.pop();

  ans+=min1+min2;
  pq.push(min1+min2);
}

cout<<"min cost"<<ans;

}


int main(){

    vector<int> ropes={4,3,2,6};

    mincost(ropes);
    return 0;

}
