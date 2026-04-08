#include <iostream>
#include <vector>
using namespace std;

int fibdp(int n, vector<int> &f)
{

    if (n == 1 ||n==0)
    {
        return n;
    }

    if (f[n] != -1)
    {
        return f[n];
    }

    f[n] = fibdp(n - 1, f) + fibdp(n - 2, f);

    return f[n];
}

int main()
{
    int n = 6;

    vector<int> f(n + 1, -1);

    cout << fibdp(n, f);
}
