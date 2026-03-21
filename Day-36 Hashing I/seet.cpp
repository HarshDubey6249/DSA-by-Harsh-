#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){

    unordered_set<string> s;

    s.insert("abc");
    s.insert("def");

    s.count("abc") ? cout<<"abc is present"<<endl : cout<<"abc is not present"<<endl;
    s.count("xyz") ? cout<<"xyz is present"<<endl : cout<<"xyz is not present"<<endl;

    s.erase("abc");

    s.count("abc") ? cout<<"abc is present"<<endl : cout<<"abc is not present"<<endl;

    return 0;
}