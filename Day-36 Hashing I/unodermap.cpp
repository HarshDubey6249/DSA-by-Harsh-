#include<iostream>
#include<vector>   
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;

    m["abc"]=1;
    m["def"]=2;
    m.count("abc")?cout<<"abc is present"<<endl:cout<<"abc is not present"<<endl;
    m.count("xyz")?cout<<"xyz is present"<<endl:cout<<"xyz is not present"<<endl;
    cout<<m["abc"]<<endl;
    cout<<m["def"]<<endl;
    m.erase("abc");
    m.count("abc")?cout<<"abc is present"<<endl:cout<<"abc is not present"<<endl;

}