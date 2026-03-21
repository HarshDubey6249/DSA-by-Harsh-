#include <iostream>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

// Binary Exponentiation
ll bin(ll x, ll n)
{
    ll res = 1;

    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % MOD;

        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

// Count Good Numbers
ll countGoodNumbers(ll n)
{
    ll evenPos = (n + 1) / 2;
    ll oddPos = n / 2;

    return (bin(5, evenPos) * bin(4, oddPos)) % MOD;
}

int main()
{
    cout << countGoodNumbers(4); // 400
}
