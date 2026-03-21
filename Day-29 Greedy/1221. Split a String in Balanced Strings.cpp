#include<iostream>
#include <string>
using namespace std;

void split(string s){
    int count=0;
    int value=0;

    for(int i=0;i<s.size();i++){

        char st=s[i];

        if(st=='R'){
            count=count+1;

        }else{
            count--;

            

        }
        if(count==0){
                value++;
            }

        
    }
    cout<<value;

}

int main(){
    string s="LLLLRRRR";

    split(s);
    return 0;
}