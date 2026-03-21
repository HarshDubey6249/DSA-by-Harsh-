#include<iostream>
using namespace std;

int main(){
  //   int n;
  //   cout<< " enter the num";
  //   cin>>n;
  // if((n&1)==1){
  //   cout<< "odd";
  // }
  // else{
  //   cout<<"even";
  // }
  int bitmash=  ~( 1 << 1);
  cout<< (6 & bitmash)<<"=========="<< ~( 1 << 1);
}