#include<iostream>
#include<cstring>
using namespace std;

char toupperCase(char word[],int n){


    int st=0;
    int end=n-1;
   // int temp;
    while(st<=end){

       if(word[st] !=word[end]){
        cout<<"not palindrome";
        return false;
        st++;
        end--;
       }
       cout<<" palindrome";
       return true;
    }
    //cout<<" palindrome";
    
}

int main(){
    char word[]= "AppA";
   int n = strlen(word);
    toupperCase(word, n);

   return 0;

}