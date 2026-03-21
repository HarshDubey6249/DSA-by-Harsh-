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

        int x = vec.size() - 1;
        int par = (x - 1) / 2;
        while (par >= 0 && vec[x] > vec[par])
        {
            swap(vec[x], vec[par]);

            x = par;
            par = (x - 1) / 2;
        }
    }

    void hipyfy(int i)
    {

        if (i >= vec.size())
        {
            return;
        }

        int l = 2 * i + 2;
        int r = 2 * i + 1;
        int maxi = i;
        if (l < vec.size() && vec[l] > vec[maxi])
        {
            maxi = l;
        }

        if (r < vec.size() && vec[r] > vec[maxi])
        {
            maxi = r;
        }

        swap(vec[maxi], vec[i]);

        if (maxi != i)
        {
            hipyfy(maxi);
        }
    }
    void pop()
    {

        swap(vec[0], vec[vec.size() - 1]);

        vec.pop_back();
        hipyfy(0);
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

    Heap hp;
    hp.push(23);
    hp.push(24);
    hp.push(25);
    hp.push(26);

    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top();
    return 0;
}