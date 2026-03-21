#include<iostream>
#include<vector>
using namespace std;

int maxActivity(vector<int>start,vector<int>end){

    //sort end time
    //select A0

    int currendtime=end[0];
    int count=1;

    for(int i=1;i<start.size();i++){
        if(start[i]>=currendtime){
            count++;
            currendtime=end[i];
        }
    }

    return count;

}

int main(){

    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};

    cout<<"max activity"<<"="<<maxActivity(start,end);
    return 0;
}