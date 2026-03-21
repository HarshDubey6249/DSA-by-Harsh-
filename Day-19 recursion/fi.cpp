#include<iostream>
using namespace std;

int  recursion(int n){
    

    while(n==0 || n==1){
        return n;
    }
    return recursion(n-1) + recursion(n-2);

}

int main(){
    for(int i=1;i<=5;i++){
cout<<recursion(i)<<endl;
    }
}