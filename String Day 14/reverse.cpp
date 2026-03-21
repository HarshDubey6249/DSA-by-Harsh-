#include<iostream>
#include<cstring>
using namespace std;

char toupperCase(char word[],int n){
    int st=0;
    int end=n-1;
   // int temp;
    while(st<=end){
    char temp =word[st];

        word[st]=word[end];

      word [end]=temp;

        st++;
        end--;


    }
}

int main(){
    char word[]= "APpLe";
   int n = strlen(word);
    toupperCase(word, n);

    cout<<word;

}