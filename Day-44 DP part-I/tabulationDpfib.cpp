
#include <iostream>
#include <vector>
using namespace std;

int fibdp(int n, vector<int> &f)
{

    for(int i=2;i<=n;i++){

        f[i]=f[i-1]+f[i-2];
    } 
    return f[n];  
}

int main()
{
    int n = 6;

    vector<int> f(n + 1);
    f[0]=0;
    f[1]=1;

    cout << fibdp(n, f);
}
