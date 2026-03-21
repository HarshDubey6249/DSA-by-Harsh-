#include<iostream>
using namespace std;

int main(){
    int num=7;
    int i=2;
    int val=1;

    num=(num & ~(1<<i));
    num =num | (val<<i);
    cout<<num;
}