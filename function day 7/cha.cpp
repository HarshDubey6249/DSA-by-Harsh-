#include<iostream>
#include<math.h>
using namespace std;

char exp(char n){
    
    if(n=='z'){
    return 'a';
}
else{
   return n+1;
}
}
int main(){
   
char n='z';
 cout<<exp(n);
 return 0;
}