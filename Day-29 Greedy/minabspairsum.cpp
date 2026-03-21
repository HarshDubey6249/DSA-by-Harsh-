#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void min_abs_pair_sum( vector<int>start,vector<int>end){

    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int ans=0;

    for(int i=0;i<start.size();i++){

        ans+= abs(start[i]-end[i]);

    }

    cout<<ans;
    
}

int main(){

    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};

    min_abs_pair_sum(start,end);

    return 0;
}