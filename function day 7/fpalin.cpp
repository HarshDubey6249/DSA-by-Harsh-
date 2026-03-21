#include<iostream>
using namespace std;

int palin(int n){
    int original=n;
    int digit=0;
    while(n>0){
        int dig=n%10;
        digit=digit*10+dig;
        n=n/10;
    }
    if(original==digit){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
}
int main(){
    int n=121;

 palin(n);
 return 0;
}