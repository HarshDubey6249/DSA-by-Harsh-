#include<iostream>
using namespace std;

int count(string str){
    int count=0;

for(int i=0;i<str.length();i++){

 if( 'a'==str[i] ||'e'==str[i]|| 'i'==str[i]||'o'==str[i]||'u'==str[i]){
   
        count++;
    }
}
cout<<count;

}

int main(){
    string str="app";
    count(str);
    return 0;

}