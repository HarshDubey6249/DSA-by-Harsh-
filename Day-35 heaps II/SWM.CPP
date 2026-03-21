//sliding window maximum
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void swm( vector<int>vec,int k){

    priority_queue<pair<int,int>>pq;

    for(int i=0;i<k;i++){

        pq.push(make_pair(vec[i],i));
    }

     cout << "max "<<pq.top().first << " ";

    for(int i=k;i<vec.size();i++){

        while(!pq.empty() &&pq.top().second<=(i-k)){
         
            pq.pop();
        }
        pq.push(make_pair(vec[i],i));
        cout<<"max "<<pq.top().first<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>vec={2,7,3,6,2,7,1,9,3,11,12,56};
    int k=3;
    swm(vec,k);

    return 0;
}