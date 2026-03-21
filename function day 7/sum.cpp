#include<iostream>
using namespace std;

int sum(int n){
    
    int digit=0;
    while(n>0){
        int dig=n%10;
        digit=digit+dig;
        n=n/10;
    }
    return digit;
  
}
int main(){
    int n=121;

 cout<<sum(n);
 return 0;
}