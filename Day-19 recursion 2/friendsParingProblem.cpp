#include <iostream>
using namespace std;

int friendsParingProblem(int n)
{

    if (n == 1 || n == 2)
    {
        return n;
    }

    int ans1 = friendsParingProblem(n - 1);
    int ans2 = (n - 1) * friendsParingProblem(n - 2);

    return ans1 + ans2;
}
int main()
{

    int n = 3;

    cout << friendsParingProblem(n);
    return 0;
}