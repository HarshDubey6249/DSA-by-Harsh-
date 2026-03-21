#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> vec = {2,2,1,3,4,5,5};
    unordered_set< int> s;
    
    for (int x:vec)
    {
        if (!s.count(x))
        {
           cout<<x<<" ,";
            s.insert(x);
        }
       
       
    }

   
    return 0;
}