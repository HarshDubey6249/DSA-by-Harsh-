#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compair(pair<double,int>p1,pair<double,int>p2){

    return p1.first > p2.first;

}

void knapsack(vector<int> value,vector<int> weight,int w){

    int n=value.size();
    
    vector<pair<double,int>> ratio(n,(make_pair(0.0,0)));

    for(int i=0;i<n;i++){

        double r=value[i]/(double)weight[i];

        ratio[i]=make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),compair);

    double ans=0.0;

    for(int i=0;i<n;i++){

        int idx=ratio[i].second;

        if(weight[idx]<=w){
            ans+=value[idx];

            w-=weight[idx];
        }else{

            ans+=ratio[i].first *w;
            w=0;
            break;
        }
    }
    cout<<ans;
}


int main()
{

    vector<int> value = {100, 60, 120};
    vector<int> weight = {20, 10, 30};

    int w = 50;

    knapsack(value,weight,w);
    return 0;
}