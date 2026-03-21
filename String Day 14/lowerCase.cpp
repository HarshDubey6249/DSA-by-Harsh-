#include<iostream>
#include<cstring>
using namespace std;

char toupperCase(char word[],int n){
    for(int i=0;i<n;i++){

        int ch=word[i];
        if(ch>='a'&& ch<='z'){
            continue;
        }else{
             word[i]= ch-'A'+'a';
        }
    }
}

int main(){
    char word[]= "APpLe";
   int n = strlen(word);
    toupperCase(word, n);

    cout<<word;

}