#include<iostream>
using namespace std;

int  recursion(int n){
    

    while(n==0){
        return 0;
    }
    cout<<n<<endl;
     recursion(n-1);

}

int main(){
recursion(5);
}