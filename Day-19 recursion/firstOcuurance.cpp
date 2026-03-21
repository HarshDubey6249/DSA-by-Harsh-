#include<iostream>
 using namespace std;

 int first_occurnce(int *arr,int n,int i){

    int tar=4;
 if(i==n){
        return -1;

    }
    

    if(arr[i]==tar){
        return i;
    }
    return first_occurnce(arr,n,i+1);

}

int main(){
int arr[5]={1,2,3,4,5};
int arr1[5]={2,4,5};

cout<<first_occurnce(arr,5,0);


}