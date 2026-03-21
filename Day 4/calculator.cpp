#include<iostream>
using namespace std;

int main(){
    int num1,num2;

    cout<<"enter num1"<<endl ;
    cin>>num1;

    cout<<"enter num2"<<endl ;
    cin>>num2;
  
    cout<<"1 for Add"<<endl ;
    cout<<"2 for Sub"<<endl ;
    cout<<"3 for MUL"<<endl ;
    cout<<"4 for Div"<<endl ;

    int choice;

    cout<<"enter your choice";
    cin>>choice;

    switch (choice)
    {
    case 1: {
           int add=num1+num2;

           cout<<add;

        break;
    }
    case 2:{
           int sub =num1+num2;
           cout<<sub;
           break;
    }
    case 3:{
          int mul=num1+num2;
          cout<<mul;
          break;
    }
    case4:{
        int div=num1+num2;
        cout<<div;
        break;
    }

    }

return 0;

}
