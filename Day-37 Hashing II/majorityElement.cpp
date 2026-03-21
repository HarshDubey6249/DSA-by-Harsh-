#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> vec = {2,2,2, 42, 5, 2, 1,1,1,1,1,16, 2, 7, 2, 1, 1, 5, 2, 3};
    unordered_map<int, int> m;
    int freq = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (m.count(vec[i]))
        {
            m[vec[i]]++;
        }else{
        m[vec[i]] = 1;
        }
    }

    for(pair<int,int> v :m){
        if(v.second>=vec.size()/3){
            cout<<v.first<<","<<"---------"<<v.second<<"-------"<<vec.size()<<endl;
        }

    }
    return 0;
}