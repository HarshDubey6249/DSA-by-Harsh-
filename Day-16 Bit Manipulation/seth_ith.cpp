//get ith bit 
#include<iostream>
using namespace std;

int main(){
    int n;
    int i;
    cout<< " enter the num";
    cin>>n;
    cout<<"enter the ith position";
    cin>>i;
  int   bit_mask= (1<<i);
  cout<<(n|bit_mask);
}