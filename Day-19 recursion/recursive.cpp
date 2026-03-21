#include<iostream>
using namespace std;

int  recursion(int n){
    

    while(n==0){
        return 1;
    }
    return(n *recursion(n-1));

}

int main(){
cout<<recursion(5);
}