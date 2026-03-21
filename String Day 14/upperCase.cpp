#include<iostream>
#include<cstring>
using namespace std;

char toupperCase(char word[],int n){
    for(int i=0;i<n;i++){

        int ch=word[i];
        if(ch>='A'&& ch<='Z'){
            continue;
        }else{
             word[i]= ch-'a'+'A';
        }
    }
}

int main(){
    char word[]= "APpLe";
   int n = strlen(word);
    toupperCase(word, n);

    cout<<word;

}