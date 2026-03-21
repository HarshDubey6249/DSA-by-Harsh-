#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// bool compare(pair<int,int>p1,pair<int,int>p2){

//     return p1.second>p2.second;

// }

// void job_seq_problem(vector<int> days, vector<int> profit){

//     int n=days.size();

//     vector<pair<int,int>>pairs;

//     for(int i=0;i<n;i++){
//         pairs.push_back({days[i],profit[i]});
//     }

//     sort(pairs.begin(),pairs.end(),compare);

//     int safedays=0;
//     int toprofit=0;

//     for(int i=0;i<n;i++){

//         if(pairs[i].first>=safedays){

//            int pr=pairs[i].second;

//             toprofit=toprofit+pr;
//             safedays++;

//         }

//     }
//     cout<<toprofit;


// }

class Job{
    public:
      int idx;
      int deadline;
      int profit;

      Job(int idx,int deadline,int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
      }
};

void job_seq_problem(vector<int> days, vector<int> profit){
int n=days.size();

 vector<pair<int,int>>pairs;

    for(int i=0;i<n;i++){
        pairs.push_back({days[i],profit[i]});
    }

    vector<Job>jobs;


    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);
    }

    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b){

        return a.profit>b.profit;
    });
  
    int safedays=0;
    int toprofit=0;

    for(int i=0;i<n;i++){

        if(jobs[i].deadline>=safedays){

            cout<<"selecting job "<<jobs[i].idx<<endl;

           int pr=jobs[i].profit;

            toprofit=toprofit+pr;
            safedays++;

        }

    }
    cout<<toprofit;

}


int main(){

    vector<int> days={4,1,1,1};
     vector<int> profit={20,10,40,10};
     job_seq_problem(days,profit);


    return 0;
}