#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,2,3,4,4,5};
   int n=5;
   int sum=0;

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){

            // cout<<"("<<i<<","<<j<<")";
            for(int a=i;a<=j;a++){
                cout<<arr[a];
            }
             cout<<",";
        }
        cout<<endl;
    }
    return 0;
}