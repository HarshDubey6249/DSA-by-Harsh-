#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpanProble(vector<int> stock, vector<int> span)
{

stack <int> s;
span[0]=-1;
 s.push(0);
//pan[0]=1;
int n=stock.size();


for(int i=1;i<n;i++){

    int curr=stock[i];
    while(!s.empty() && curr>=stock[s.top()]){
        s.pop();
    }

    if(s.empty()){
        span[i]=i+1;
    }else{
        int prevhigh=s.top();
        span[i]=i-prevhigh;
    }
    s.push(i);
}

    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    vector<int> stock = {2,1,5,6,2,3};
    vector<int> span = {0, 0, 0, 0, 0,0};

    stockSpanProble(stock,span);

    return 0;
}