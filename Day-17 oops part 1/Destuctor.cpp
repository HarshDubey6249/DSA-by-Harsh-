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
            this->name = name;
            this->color = color;

            milage = new int; // Dynamic Allocation
            *milage = 12;
        }

        // Deep Copy Constructor
        Car(const Car &original){
            cout << "copy constructor" << endl;
            name = original.name;
            color = original.color;

            milage = new int;      // allocate new memory
            *milage = *original.milage; // copy value
        }

        // Proper Destructor
        ~Car(){
            cout << "Destructor called" << endl;
            if(milage != NULL){
            delete milage;   // free allocated memory
            milage=NULL;
        }
    }
};

int main(){
    Car c1("harsh","white");
   
    cout << c1.name << endl;
    cout << c1.color << endl;
    cout << *c1.milage << endl;

   

    return 0;
}
