#include<iostream>
using namespace std;

int main(){
   int n,tabel;

   cout<<"Enter the tabel you want to print= ";
   cin>>n;

   for(int i=1;i<=10;i++){
     tabel=n*i;
    cout<<tabel<<endl;
   }
   
    
    return 0;
}
