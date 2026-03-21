#include<iostream>
using namespace std;

// int  pow(int x,int n){
    
//   if(n==0){
//         return 1;
//     }

//    return x*pow(x,n-1);

// }

int  pow(int x,int n){
    
  if(n==0){
        return 1;
    }
  int halfpow= pow(x,n/2);
  int halfpowS=halfpow*halfpow;

  if(n %2!=0){
    return x*halfpowS;
  }


  return halfpowS;
   return x*pow(x,n-1);

}

int main(){
cout<<pow(2,10);
}