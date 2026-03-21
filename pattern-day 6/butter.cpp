#include<iostream>
using namespace std;

int main(){
     int n=4;
//     //upper
    for(int i=1;i<=n;i++){
//     //left
   for(int j=1;j<=i;j++){
     cout<<"*";
 }

  for(int j=1;j<=2*(n-i);j++){
    cout<<" ";
  }
      for(int j=1;j<=i;j++){
     cout<<"*";
 }
  cout<<endl;
   }

   //lower
   for(int i=n;i>=1;i--){
//     //left
   for(int j=1;j<=i;j++){
     cout<<"*";
 }

  for(int j=1;j<=2*(n-i);j++){
    cout<<" ";
  }
      for(int j=1;j<=i;j++){
     cout<<"*";
 }
  cout<<endl;
   }
return 0;
}