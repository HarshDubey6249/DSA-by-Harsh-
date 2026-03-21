#include<iostream>
#include<queue>
#include<string>
using namespace std;

int First_string_repeation(string str){

    queue<char> q;

    char freq[26]={0};

    for(int i=0;i<str.size();i++){
        int ch=str[i];

        q.push(ch);
        freq[ch-'a']++;
    

    while(!q.empty() && freq[q.front()-'a']>1){
        q.pop();
    }

    if(q.empty()){
       cout<<"-1\n";
    }else{

        cout<<q.front()<<endl;
    }
    }
}


int main(){

    string str="aabccxb";

    First_string_repeation(str);
    return 0;
}