#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> vec1 = {2,2,1,3,4,5,5};
     vector<int> vec2 = {2,2,1,5,6,11,2,2,3,4,5,6,7,8,9,10,3,4,5,5};
    unordered_set< int> s;
    
    for (int x:vec1)
    {
        s.insert(x);
    }
    for (int x:vec2)
    {
        s.insert(x);
    }

    for (int x:s)
    {
        cout<<x<<",";
    }
 
   
    return 0;
}