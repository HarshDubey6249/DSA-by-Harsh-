#include<iostream>
#include<string>
using namespace std;

class Car{
    private:
        string name;
        string color;
        int *milage;

    public:
        Car(string nameVal,string colorVal){
            cout<<"constructor"<<endl;
            name=nameVal;
            color=colorVal;
            milage=  new int;
            *milage=12;
        }

        Car(Car &original){
            cout<<"copy";
            name=original.name;
            color=original.color;
            *milage=12;
        }
    void getPercentage(){
            cout<<" hi am harsh"<<endl;
        }
        //getters

        string getNameval(){
           return name;
        }
};
int main(){
    Car c1("harsh","white");
    cout<<"car name.."<<c1.getNameval()<<endl;
    return 0;

}