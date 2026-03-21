#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}

void maxlength(vector<int>start,vector<int>end){

    int n=end.size();
    vector<pair<int,int>> pair;

    for(int i=0;i<start.size();i++){
        pair.push_back({start[i],end[i]});
    }

    sort(pair.begin(),pair.end(),compare);

    int ans=1;
    int currend=pair[0].second;

    for(int i=1;i<start.size();i++){
        if(pair[i].first>=currend){
            ans++;
            currend=pair[i].second;
        }
    }

    cout<<ans;

}


int main(){
    vector<int>start={5,39,5,27,50};
    vector<int>end={24,60,28,40,90};

  maxlength(start,end);
  return 0;

}