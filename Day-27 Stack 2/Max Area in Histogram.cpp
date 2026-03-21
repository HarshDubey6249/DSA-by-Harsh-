#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void max(vector<int> height)
{
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    s.push(0);
    nsl[0] = -1;
    for (int i = 1; i < n; i++)
    {

        int curr = height[i];

        while (!s.empty() && curr <= height[s.top()])
        {
            s.pop();
        }

        if (s.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = s.top();
        }

        s.push(i);
    }
    for (int i = 0; i < height.size(); i++)
    {
        cout << nsl[i] << " ";
    }
    cout << endl;
    cout<<"=====================================================";

    while (!s.empty())
    {
        s.pop();
    }

    s.push(n-1);
    nsr[n-1]=n;
    for(int i=n-2;i>=0;i++){
        int curr = height[i];
        while(!s.empty()&& curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=n;
        }else{
            nsr[i]=s.top();
        }
        s.push(i);

    }

      for (int i = 0; i < height.size(); i++)
    {
        cout << nsr[i] << " ";
    }
    cout << endl;
    cout<<"=================================================";

    int maxArea=0;
    for(int i=0;i<n;i++ ){
        int h=height[i];

        int area=h*(nsr[i]-nsl[i]-1);

        maxArea=max(area,maxArea);
    }

  cout << "Max area is: " << maxArea << endl;

}


int main()
{

    vector<int> arr = {2, 1, 5, 6, 2, 3};

    max(arr);

    return 0;
}
