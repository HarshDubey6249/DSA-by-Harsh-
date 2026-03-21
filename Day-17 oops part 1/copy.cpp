#include<iostream>
#include<string>
using namespace std;

class Car{
    public:
        string name;
        string color;
        int *milage;

    
        Car(string name,string color){
            cout<<"constructor"<<endl;
           this->name=name;
           this-> color=color;
            milage=  new int; //Dynamic Allocation
            *milage=12;
        }

        Car(Car &original){
          //  cout<<"copy";
            name=original.name;
            color=original.color;
            milage=original.milage;
        }
    
};
int main(){
    Car c1("harsh","white");
    Car c2(c1); //custom copy
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
     cout<<*c2.milage<<endl;
    return 0;

}