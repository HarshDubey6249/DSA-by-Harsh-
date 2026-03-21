#include <iostream>
#include <queue>
using namespace std;

// class Student
// {
//     public:
//     string name;
//     int marks;

//     Student(string name, int marks)
//     {

//         this->name = name;
//         this->marks = marks;
//     }

    // bool operator < (const Student &obj) const{
    //     return this->marks>obj.marks;
    // }
// };


struct Compare_pair{
    bool operator()(pair<string,int> &p1,pair<string,int> &p2){

        return p1.second<p2.second;
    }

};


int main()
{

    // priority_queue<Student> pq;
    // priority_queue<pair<string,int>> pq;  //max pair
    priority_queue<pair<string,int>, vector<pair<string,int>>,Compare_pair> pq;   //min


    pq.push(make_pair("harsh", 98));
     pq.push(make_pair("trisha", 95));
      pq.push(make_pair("utkarsh", 90));
       pq.push(make_pair("sanket", 90));

       while (!pq.empty())
       {
       cout<<pq.top().first<<" "<<pq.top().second<<endl;
       pq.pop();
       }
       
}