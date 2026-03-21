#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpanProble(vector<int> stock, vector<int> span)
{

    stack<int> s;

    s.push(0);
    span[0] = 1;
    for (int i = 1; i < stock.size(); i++)
    {

        int currPrice=stock[i];
        while(!s.empty() &&currPrice>= stock[s.top()]){
            s.pop();
        }

        if(s.empty()){

            span[i]= i+1;

        }else{

          int preHigh=s.top();

          span[i]=i-preHigh;

        }
    }

    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    vector<int> stock = {2,1,5,6,2,3};
    vector<int> span = {0, 0, 0, 0, 0, 0};

    stockSpanProble(stock,span);

    return 0;
}