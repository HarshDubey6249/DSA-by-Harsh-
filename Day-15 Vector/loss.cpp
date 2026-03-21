#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lossEle(vector<int> vec)
{

    sort(vec.begin(), vec.end());

    int miss=-1;
    int dup=-1;

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[i - 1])
        {
            dup = vec[i];
        }

    }
    
    int n=vec.size();
     
    int expectedSum=n*(n+1)/2;
   


    int actualSum=0;

    for(int x:vec){

        actualSum+=x;
      
    }
    

    miss=expectedSum -(actualSum-dup);

    cout<<"missing value"<<miss<<endl;

    cout<<"==========================="<<endl;

    cout<<"duplicate value"<<dup<<endl;

}

int main()
{

    vector<int> vec = {1,2,3,4,5,6,6,7,9,10};
    lossEle(vec);

    return 0;
}