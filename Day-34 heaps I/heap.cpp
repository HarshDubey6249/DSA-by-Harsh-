#include <iostream>
#include <vector>
using namespace std;

class Heap
{

    vector<int> vec;

public:
    void push(int val)
    {

        vec.push_back(val);

        int x = vec.size() - 1; // child
        int par = (x - 1) / 2;  // parent

        while (par >= 0 && vec[par] < vec[x])
        {

            swap(vec[x], vec[par]);
            x = par;
            par = (x - 1) / 2;
        }
    }
    void hepify(int i)
    {

        if (i >= vec.size())
        {
            return;
        }

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int maxi = i;

        if (l < vec.size() && vec[l] > vec[maxi])
        {
            maxi = l;
        }

        if (r < vec.size() && vec[r] > vec[maxi])
        {
            maxi = r;
        }
        swap(vec[i], vec[maxi]);
        if (maxi != i)
        {
            hepify(maxi);
        }
    }

    void pop()
    {
        int x = vec.size() - 1;
        swap(vec[0], vec[x]);

        vec.pop_back();
        hepify(0);
    }

    int top()
    {
        return vec[0];
    }
    bool empty()
    {
        return vec.size() == 0;
    }
};
int main()
{

    Heap h;
    h.push(12);
    h.push(22);
    h.push(14);
    h.push(32);
    h.push(54);
    h.push(10);

    cout << h.top();
     h.pop();
     cout << h.top();
    return 0;
}