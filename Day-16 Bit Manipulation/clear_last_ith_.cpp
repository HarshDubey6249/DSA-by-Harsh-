#include<iostream>
using namespace std;

int main(){
    int i=2;
    int num=15;
    int bitmask= (~0)<< i;
     num=num & bitmask;

    cout <<num;
}