#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
    public:

     int count;
     int idx;

     Row(int count,int idx){
        this->count=count;
        this->idx=idx;
     }

     bool operator <(const Row &obj) const{

        if(this->count==obj.count){

            return this->idx > obj.idx;
        }
            return this->count>obj.count;
     }
};

void weakest(vector<vector<int>> &v,int k){

    priority_queue<Row> pq;

    for(int i=0;i<v.size();i++){
        int count=0;

        for(int j=0;j<v[i].size() && v[i][j]==1;j++){
            count++;
        }

        pq.push(Row(count,i));
    }

    for(int i=0;i<k;i++){
        cout << "weak " << pq.top().idx << endl;
        pq.pop();
    }
}

int main(){

    
    vector<vector<int>> v{
        {1,0,0,0,0},
        {1,1,1,1,1},
        {1,0,0,0,0},
        {1,0,0,0,0},
        
    };

    int k = 2;
    weakest(v,k);
   

}